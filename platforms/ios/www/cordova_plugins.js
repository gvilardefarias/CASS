cordova.define('cordova/plugin_list', function(require, exports, module) {
module.exports = [
  {
    "id": "cordova-plugin-bluetooth-serial.bluetoothSerial",
    "file": "plugins/cordova-plugin-bluetooth-serial/www/bluetoothSerial.js",
    "pluginId": "cordova-plugin-bluetooth-serial",
    "clobbers": [
      "window.bluetoothSerial"
    ]
  },
  {
    "id": "cordova-plugin-cpp-bridge.CordovaCppBridge",
    "file": "plugins/cordova-plugin-cpp-bridge/www/CDVCppBridge.js",
    "pluginId": "cordova-plugin-cpp-bridge",
    "clobbers": [
      "cpp"
    ]
  }
];
module.exports.metadata = 
// TOP OF METADATA
{
  "cordova-plugin-bluetooth-serial": "0.4.7",
  "cordova-plugin-cpp-bridge": "0.0.7",
  "cordova-plugin-whitelist": "1.3.2"
};
// BOTTOM OF METADATA
});