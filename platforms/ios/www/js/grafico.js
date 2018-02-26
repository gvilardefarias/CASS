document.addEventListener("deviceready", onDeviceReady, false);

var datas = [], conected = true, dA = 0, dN = 0, contin = true;
var processamento = Module.cwrap('main_processamentoEMG', 'string');
var add = Module.cwrap('addValue', null, ['number', "number"]);

for(var i=0;i<300;i++)
    datas.push(0);

var isConected = function(){
    tempoI = Date.now();
    conected = true;
}
var isDisconected = function(){
    conected = false;
}

var getData = function(data){
    if(datas.length>300)
        datas = datas.slice(1);

    datas.push(data);

    var res = [];

    for(var i=0;i<datas.length;++i)
        res.push([i, datas[i]])
    
    return res;
}

var update = function(data){
    if(contin){
        add(data, Date.now());

        plot1.setData([getData(data)]);

        plot1.draw();
    }
}

var irRelatorio = function(){
    $(".grafico").hide();
    $(".resultados").show();


    dados = dados.split(":");
    dados1 = dados[0].split(",");
    dados2 = dados[1].split(",");

    dados1[0] = parseFloat(dados1[0]);
    dados1[1] = parseFloat(dados1[1]);
    dados1[2] = parseFloat(dados1[2]);

    $("#test4").text((dados1[1]/(dados1[0]/1000)).toFixed(2) + " contrações/s");
    $("#test5").text((dados1[0]/1000).toFixed(2) + " s");

    $("#test7").text(dados1[2] + " s");

    for(var i=0;i<dados2.length-1;i++){
        $(".lista").append("<p>"+(Math.abs(parseFloat(dados2[i])-tempoI)/1000).toFixed(2)+" s</p>");
    }
}

var stopSuccess = function(){
    dados = processamento();

    $(".btn").click(irRelatorio);
   
    $(".btn").text("relatorio");

    $(".btn").css("background-color", "yellow");
    $(".btn").css("color", "black");
}

var parar = function(){
    contin = false;
    
    bluetoothSerial.write("E", null, null);
    bluetoothSerial.unsubscribe(stopSuccess, null);
}

var iniciar = function(){
    $(".btn").click(parar);
    $(".btn").text("Parar");
    $(".btn").css("background-color", "red");
    $(".btRelatorio").hide();

    plot1 = $.plot("#placeholder", [getData(0)], {
        series: {
            shadowSize: 0   
        },
        yaxis: {
            min: 0,
            max: 1024
        },
        xaxis: {
            show: false
        }
    });

    bluetoothSerial.write("S", isConected, isDisconected);
    bluetoothSerial.subscribe('\n', update, null);
}

function onDeviceReady(){
    $(".resultados").hide();
    $(".btn").click(iniciar);
    $(".btRelatorio").hide();
}