document.addEventListener("deviceready", onDeviceReady, false);

var datas = [], conected = true;

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
    plot.setData([getData(data)]);

    plot.draw();
}

var irRelatorio = function(){
    window.location = "relatorio.html";
}

var stopSuccess = function(){
    $(".btn").click(irRelatorio);
    $(".btn").text("Relatorio")
    $(".btRelatorio").show();
}

var parar = function(){
    bluetoothSerial.unsubscribeRawData(stopSuccess, parar);
}

var iniciar = function(){
    $(".btn").click(parar);
    $(".btn").text("Parar")
    $(".btRelatorio").hide();

    bluetoothSerial.write("s", isConected, isDisconected);

    while(!isConected()) continue;

    plot = $.plot("#placeholder", [getData()], {
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

    bluetoothSerial.subscribeRawData(update, null);
}

function onDeviceReady(){
    $(".btRelatorio").hide();
    $(".btn").click(iniciar);
}