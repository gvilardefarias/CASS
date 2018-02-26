function onDeviceReady(){
    $(".ok").text(sessionStorage.getItem("dadosProcessamento"));
    dados = sessionStorage.getItem("dadosProcessamento").split(":")[0].split(",");

    $("#test4").text(str(float(dados[1])/(float(dados[0])/1000)) + " contrações/s");
    $("#test5").text(str(float(dados[0])/1000) + " s");

    $("#test7").text(dados[2] + " s");
}