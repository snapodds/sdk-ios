//
// Copyright (c) 2022 Snapscreen Application GmbH <https://snapscreen.com>
//

import UIKit
import SnapscreenFramework

class ViewController: UIViewController {

    @IBAction func snap(_ sender: Any) {
        let snapViewController = SnapViewController(configuration: SnapConfiguration(), snapDelegate: self)
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
    
    func snapscreenSnapViewController(_ viewController: SnapViewController, didSnapSportEvent sportEvent: SportEventSnapResultEntry) -> Bool {
        viewController.dismiss(animated: true, completion: nil)
        
        DispatchQueue.main.async {
            let alert = UIAlertController(title: "Snapped Sport Event", message: "Successfully snapped sport event with id \(sportEvent.sportEvent?.eventId ?? -1) on \(sportEvent.tvChannel?.name ?? "Unknown channel")", preferredStyle: .alert)
            alert.addAction(UIAlertAction(title: "OK", style: .default, handler: nil))
            self.present(alert, animated: true, completion: nil)
        }
        return true
    }

}
