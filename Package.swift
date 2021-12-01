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
            targets: ["Snapscreen"])
    ],
    targets: [
        .binaryTarget(
            name: "Snapscreen",
            path: "SnapscreenFramework.xcframework"
        )
    ]
)