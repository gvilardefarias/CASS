document.addEventListener("deviceready", onDeviceReady, false);

var datas = [], conected = true, dA = 0, dN = 0, contin = true;
var processamento = Module.cwrap('main_processamentoEMG', 'string');
var add = Module.cwrap('addValue', null, ['number', "number"]);

for(var i=0;i<300;i++)
    datas.push(0);

var isConected = function(){
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

        plot.setData([getData(data)]);

        plot.draw();
    }
}

var irRelatorio = function(){
    window.location = "relatorio.html";
}

var stopSuccess = function(){
    //$(".btn").click(irRelatorio);
   
    $(".btn").text(processamento());

    $(".btn").css("background-color", "yellow");
    $(".btn").css("color", "black");
    $(".btRelatorio").show();
}

var parar = function(){
    contin = false;
    
    bluetoothSerial.write("E", null, null);
    bluetoothSerial.unsubscribe(stopSuccess, parar);
}

var iniciar = function(){
    $(".btn").click(parar);
    $(".btn").text("Parar");
    $(".btn").css("background-color", "red");
    $(".btRelatorio").hide();

    plot = $.plot("#placeholder", [getData(0)], {
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
    $(".btn").click(iniciar);
    $(".btRelatorio").hide();
}