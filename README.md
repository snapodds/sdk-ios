## Documentation

For the full API documentation go to https://snapodds.github.io/snapscreen-ios

## Support
In case of any questions or problems please contact us at [support@snapscreen.com](mailto:support@snapscreen.com).

## Requirements

Snapscreen requires at least **iOS 13**.

## Integrating Snapscreen

### Swift Package Manager

Integration via SwiftPM is the easiest and recommended way to use Snapscreen. Add the following to your Package.swift file

```
dependencies: [
    .package(url: "https://github.com/snapodds/snapscreen-ios.git", .upToNextMajor(from: "2.0.0"))
]
```

### XCFrameworks

SnapscreenFramework is provided as an iOS xcframework and bundles everything necessary for it to operate.

#### Add the SnapscreenFramework xcframework

Drag the SnapscreenFramework xcframework file to your iOS project. Xcode should automatically add it to the project's **Frameworks, Libraries, and Embedded Content** section in your General Settings. Make sure to change the **Embed** setting to **Embed & Sign**.

## Using Snapscreen

### Obtain a client ID and secret

Contact Snapscreen to get a clientID and secret for your application.

### Import SnapscreenFramework

Add the following line to all classes where you want to access the SnapscreenFramework functionality.

```
import SnapscreenFramework
```

### Add Camera Permission Usage Description if necessary

If you want to access the snapping functionality, starting with iOS 10 it is required by provide a usage description for the camera. This can be done by adding the key **NSCameraUsageDescription** in your application's Info.plist.

### Initialize SnapscreenFramework

In order to initialize Snapscreen, you need to call the following class method in your AppDelegate in application:didFinishLaunchingWithOptions:

```
Snapscreen.setup(withClientId: "your-client-id", clientSecret: "your-client-secret", environment: .production)
```

If you are provided with a custom backend URL by Snapscreen, you can use the following method to initalize the SDK:

```
Snapscreen.setup(withClientId: "your-client-id", clientSecret: "your-client-secret", backendURL: "url")
```

If preferred, you can additionally set the country and usState information based on your user's location:

```
Snapscreen.instance?.country = "US"
Snapscreen.instance?.usState = "NJ"
```

Once you have initialized Snapscreen, you can also retrieve it by calling

```
Snapscreen.instance
```

## Snapping Sports content

In order to snap a TV image and search for Sport event, you need to create and present an instance of **SnapViewController**. You can customize the snap settings by configured the **SnapConfiguration** you pass to the initializer. The **SnapscreenSnapDelegate** will receive a callback once a sport event was successfully snapped.

It is recommended that you present the SnapViewController in a UINavigationController. 

Additionally you need to configure the cancel navigation item if you want to provide the user with the option to cancel the Snap.


```
let snapViewController = SnapViewController(configuration: SnapConfiguration(), snapDelegate: self)
snapViewController.isModalInPresentation = true
snapViewController.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .cancel, target: self, action: #selector(cancelSnap))
self.present(UINavigationController(rootViewController: snapViewController), animated: true, completion: nil)
```

Once a sport event was successfully snapped, the following method is called in your SnapscreenSnapDelegate:

```
func snapscreenSnapViewController(_ viewController: SnapViewController, didSnapSportEvent sportEvent: SportEventSnapResultEntry) -> Bool {
  return true
}
```

The boolean return value indicates if you want the **SnapViewController** to immediately stop snapping. This is most likely the case since you want to present some follow-up UI for the found sport event.

Before you present the Snap UI, we recommend that you ask for the permission to use the camera with the following code snippet and only redirect the user to the Snap UI when the permission has been granted.

```
let status = AVCaptureDevice.authorizationStatus(for: .video)
switch status {
  case .authorized:
      presentSnap()
  case .notDetermined:
      AVCaptureDevice.requestAccess(for: .video) { [weak self] (granted) in
          DispatchQueue.main.async { [weak self] in
              if granted {
                  self?.presentSnap()
              } else {
                  presentAlertWithLinkToSettings()
              }
          }
      }
  case .denied: fallthrough
  case .restricted:
      presentAlertWithLinkToSettings()
  @unknown default:
      presentSnap()
}
```

## Fetching Odds for a sport event

In order to fetch odds for a sport event provided by Snapscreen in a consolidated form, you can use the following call to SnapscreenFramework:

```
Snapscreen.instance?.getOddsForSportEvent(withId: sportEventId, completion: { [weak self] result in
}
```

The completion block is called either with a valid result or nil. See the documentation for the structure and content of the returned result.

Please note that for fetching odds via Snapscreen we highly recommend setting the **country** and **usState** fields on the snapscreen instance to receive accurate results.

## Customization - UI & Localization

If you want to customize any aspect of the **SnapViewController**, including displayed messages as well as colors, you can use the **SnapscreenUIConfiguration** object on the Snapscreen instance.

```
Snapscreen.instance?.uiConfiguration.primaryColor = UIColor.red
```

Make sure to do all your desired customizations before presenting a SnapViewController.
You can also modify the configuration between presentations of the SnapViewController. Modifications while the ViewController is present are not guaranteed to be respected.

## Note about Apple Silicon Simulators

Please note that SnapscreenFramework current only includes simulator architecture for i386_x86 and not arm64 which means you currently cannot run an app with SnapscreenFramework included on iOS simulators on Apple Silicon Macs. As a workaround you can either use your app on a device or run Xcode via Rosetta to force the simulator to run with i386_x86.

We are working on an update to the SDK to also include arm64 architecture for the iOS simulator.

## Example

For a sample using the Snapscreen SDK, see the included Example project and reconfigure with your own client ID and secret before running.

## Support

In case of any questions or problems please contact us at [support@snapscreen.com](mailto:support@snapscreen.com).
