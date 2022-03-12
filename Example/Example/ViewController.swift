//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

import UIKit
import SnapscreenFramework

class ViewController: UIViewController {

    @IBAction func startSportsMedia(_ sender: Any) {
        let snapViewController = SnapViewController.forSportsMedia(configuration: SnapConfiguration())
        snapViewController.isModalInPresentation = true
        snapViewController.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .cancel, target: self, action: #selector(cancelSnap))
        self.present(UINavigationController(rootViewController: snapViewController), animated: true, completion: nil)
    }
    
    @IBAction func startSportsOperator(_ sender: Any) {
        let snapViewController = SnapViewController.forSportsOperator(configuration: SnapConfiguration(), snapDelegate: self)
        snapViewController.isModalInPresentation = true
        snapViewController.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .cancel, target: self, action: #selector(cancelSnap))
        self.present(UINavigationController(rootViewController: snapViewController), animated: true, completion: nil)
    }
    
    @objc private func cancelSnap() {
        dismiss(animated: true, completion: nil)
    }
    
    @IBAction func loadOdds(_ sender: Any) {
        Snapscreen.instance?.getOddsForSportEvent(withId: 494, completion: { result in
            let alert = UIAlertController(title: result != nil ? "Fetched odds" : "No odds found", message: result != nil ? "Successfully fetched odds from \(result?.sportsBooks?.count ?? 0) providers for sport event" : nil, preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
            self.present(alert, animated: true, completion: nil)
        })
    }
}

extension ViewController: SnapscreenSnapDelegate {
    
    func snapscreenSnapViewController(_ viewController: SnapViewController, didSnapSportEvent sportEvent: SportEventSnapResultEntry) {
        viewController.dismiss(animated: true) { [weak self] in
            DispatchQueue.main.async {
                let alert = UIAlertController(title: "Snapped Sport Event", message: "Successfully snapped sport event with id \(sportEvent.sportEvent?.eventId ?? -1) on \(sportEvent.tvChannel?.name ?? "Unknown channel")", preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "OK", style: .cancel, handler: nil))
                
                if let event = sportEvent.sportEvent {
                    alert.addAction(UIAlertAction(title: "Show Odds", style: .default, handler: { [weak self] _ in
                        let resultsViewController = OddsResultsViewController(sportEvent: event, tvChannel: sportEvent.tvChannel)
                        self?.present(UINavigationController(rootViewController: resultsViewController), animated: true, completion: nil)
                    }))
                }
                self?.present(alert, animated: true, completion: nil)
            }
        }
    }

}
