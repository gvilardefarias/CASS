document.addEventListener("deviceready", onDeviceReady, false);

var uuid = "";
var macAddress = "";

var connectSuccess = function(){
    window.location = "grafico.html";
}

var conectar = function(){
    if(cordova.platformId === "ios")
        bluetoothSerial.connect(uuid, connectSuccess, null);
    else
        bluetoothSerial.connect(macAddress, connectSuccess, null); 
}

var bAtivado = function(){
    $("#btMessage").text("Conectar");
    $("#btMessage").addClass("disabled");

    $("#btMessage").click(conectar());
};

var bDesativado = function(){
    $("#btMessage").text("Ativar");
    $("#btMessage").css("background-color", "red");

    $("#btMessage").click(bluetoothSerial.enable(bAtivado, bDesativado));
};

function onDeviceReady(){
    $(".btn-con").css("margin-left", -($(".btn-con").width()/2));

    bluetoothSerial.isEnabled(bAtivado, bDesativado);
}

