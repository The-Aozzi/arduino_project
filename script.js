function fetchData() {
    fetch("http://127.0.0.1:5000", { mode: 'cors' }).then((response) => response.json()).then(data => {
        document.getElementById("a").innerHTML = "<b>LM75A</b>: "+data['LM75A']+" °C <br><b>DS18B20</b>: "+data["DS18B20"]+" °C"
        
    })
}

setInterval(fetchData, 500);

