document.addEventListener("deviceready", onDeviceReady, false);

var uuid = "";
var macAddress = "";

var connectSuccess = function(){
    window.location = "grafico.html";
}

var esperarConexao = function(){
    bluetoothSerial.isConnected(connectSuccess, esperarConexao);
}

var bAtivado = function(){
    $("#btMessage").text("Conecte ao dispositivo");
    $("#btMessage").css("background-color", "green");
    $("#btMessage").addClass("disabled");

    $("#btMessage").click(null);

    esperarConexao();
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