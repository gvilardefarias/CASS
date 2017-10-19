document.addEventListener("deviceready", onDeviceReady, false);

var uuid = "";
var macAddress = "";

var connectSuccess = function(){
    window.location = "grafico.html";
}

var conectado = function(){
    bluetoothSerial.isConnected(connectSuccess, null);
}

var bAtivado = function(){
    $("#btMessage").text("Conectado");
    $("#btMessage").css("background-color", "green");

    $("#btMessage").click(conectado);
};

var bDesativado = function(){
    $("#btMessage").text("Ativar");
    $("#btMessage").css("background-color", "red");

    $("#btMessage").click(bluetoothSerial.enable(bAtivado, bDesativado));
};

function onDeviceReady(){
    $(".btn-con").css("margin-left", -($(".btn-con").width()/2));
    $(".rel").click(function(){
        window.location = "relatorio.html";
    });
    $(".gra").click(connectSuccess);

    bluetoothSerial.isEnabled(bAtivado, bDesativado);
}