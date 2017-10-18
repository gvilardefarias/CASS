document.addEventListener("deviceready", onDeviceReady, false);

function onDeviceReady() {
    $(".btn-con").css("margin-left", -($(".btn-con").width()/2));

    var bAtivado = function() {
                        $("#btMessage").text("Ativado");
                        $("#btMessage").addClass("disabled");

                        $("#btMessage").click(null);
                    };
    var bDesativado = function() {
                            $("#btMessage").text("Ativar");
                            $("#btMessage").css("background-color", "red");

                            $("#btMessage").click(bluetoothSerial.enable(bAtivado, bDesativado));
                        };

    bluetoothSerial.isEnabled(bAtivado, bDesativado);
}

