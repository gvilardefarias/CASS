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

var getData = function(){
    if(datas.length>300)
        datas = datas.slice(1);

    bluetoothSerial.read(function (data) {
        datas.push(data);

        isConected();
    }, isDisconected);

    //datas.push(Math.random()*100);

    console.log(datas);

    var res = [];

    for(var i=0;i<datas.length;++i)
        res.push([i, datas[i]])
    
    return res;
}

function update(){
    plot.setData([getData()]);

    plot.draw();
    
    if(isConected())
        setTimeout(update, 10);
}


function onDeviceReady(){
    bluetoothSerial.write("s", isConected, isDisconected);

    if(isConected()){
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

        update();
    }
}