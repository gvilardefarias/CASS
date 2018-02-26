document.addEventListener("deviceready", onDeviceReady, false);

var uuid = "";
var macAddress = "";
var dG = ["0"];

var connectSuccess = function(){
    window.location = "grafico.html";
}

var setDevice = function(device){
    $("#btMessage").text(device);
    bluetoothSerial.connect(device, connectSuccess, onDeviceReady);
}

var abrirModal = function(){
    $('#modal').modal('open');
}

var showDevicesS = function(devices){
    $("#dis").each(function(){ 
        $(this).remove();
    });

    for(device in devices){
        $('#dis').append(`<a href="#!" class="collection-item" id="`+devices[device].id+`">`+devices[device].name+`</a>`);
        $(`#`+devices[device].id).click(setDevice(devices[device].id));
    }

    
    $("#btMessage").text("Dispositivos");
    $("#btMessage").click(abrirModal);
    abrirModal();
}

var showDevices = function(){
    bluetoothSerial.list(showDevicesS, onDeviceReady);
}

var bAtivado = function(){
    $("#btMessage").text("Dispositivos");
    $("#btMessage").css("background-color", "green");

    $("#btMessage").click(showDevices);
};

var bDesativado = function(){
    $("#btMessage").text("Ativar");
    $("#btMessage").css("background-color", "red");

    $("#btMessage").click(bluetoothSerial.enable(bAtivado, bDesativado));
};

function onDeviceReady(){
    $('.modal').modal();
    $(".btn-con").css("margin-left", -($(".btn-con").width()/2));
    $(".rel").click(function(){
        window.location = "relatorio.html";
    });
    $(".gra").click(connectSuccess);

    bluetoothSerial.isEnabled(bAtivado, bDesativado);
}