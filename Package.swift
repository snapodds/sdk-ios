// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "Snapscreen",
    platforms: [
         .iOS(.v13)
    ],
    products: [
        .library(
            name: "Snapscreen",
            targets: ["SnapscreenFramework"])
    ],
    targets: [
        .binaryTarget(
            name: "SnapscreenFramework",
            path: "SnapscreenFramework.xcframework"
        )
    ]
)