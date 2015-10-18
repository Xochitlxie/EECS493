function drawHouse() {
        var canv = document.getElementById("myCanvas");
        canv.width = 300;
        canv.height = 300;
        if(document.getElementById("draw").value=="0"){
            console.log(1111)
            document.getElementById("draw").value = 1;
            var house = canv.getContext("2d");
            //large rectangle
            house.fillStyle = "blue";
            house.fillRect(10,100,200,100);
            //door
            house.fillStyle = "black";
            house.fillRect(100,140,30,60);
            //wall
            house.fillStyle = "red";
            house.beginPath();
            house.moveTo(210,200);
            house.lineTo(230,185);
            house.lineTo(230,85);
            house.lineTo(210,100);
            house.closePath();
            house.fill();
            //roof1
            house.fillStyle="red";
            house.beginPath();
            house.moveTo(10,100);
            house.lineTo(210,100);
            house.lineTo(110,50)
            house.closePath();
            house.fill();
            //roof2
            house.fillStyle="blue";
            house.beginPath();
            house.moveTo(210,100);
            house.lineTo(230,85);
            house.lineTo(110,50);
            house.closePath();
            house.fill();
            
        }else if(document.getElementById("draw").value =="1"){
            console.log(22222)
            document.getElementById("draw").value = 2;
           var house = canv.getContext("2d");
            //large rectangle
            house.fillStyle = "red";
            house.fillRect(10,100,200,100);
            //door
            house.fillStyle = "black";
            house.fillRect(100,140,30,60);
            //wall
            house.fillStyle = "blue";
            house.beginPath();
            house.moveTo(210,200);
            house.lineTo(230,185);
            house.lineTo(230,85);
            house.lineTo(210,100);
            house.closePath();
            house.fill();
            //roof1
            house.fillStyle="blue";
            house.beginPath();
            house.moveTo(10,100);
            house.lineTo(210,100);
            house.lineTo(110,50)
            house.closePath();
            house.fill();
            //roof2
            house.fillStyle="red";
            house.beginPath();
            house.moveTo(210,100);
            house.lineTo(230,85);
            house.lineTo(110,50);
            house.closePath();
            house.fill();

        }else{
            console.log(333);
            document.getElementById("draw").value = 0;
            document.getElementById("myCanvas").style.border= "10px solid red";
            var house = canv.getContext("2d");
            //large rectangle
            house.fillStyle = "blue";
            house.fillRect(10,100,200,100);
            //door
            house.fillStyle = "black";
            house.fillRect(100,140,30,60);
            //wall
            house.fillStyle = "red";
            house.beginPath();
            house.moveTo(210,200);
            house.lineTo(230,185);
            house.lineTo(230,85);
            house.lineTo(210,100);
            house.closePath();
            house.fill();
            //roof1
            house.fillStyle="red";
            house.beginPath();
            house.moveTo(10,100);
            house.lineTo(210,100);
            house.lineTo(110,50)
            house.closePath();
            house.fill();
            //roof2
            house.fillStyle="blue";
            house.beginPath();
            house.moveTo(210,100);
            house.lineTo(230,85);
            house.lineTo(110,50);
            house.closePath();
            house.fill();
            alert("The house survived 3 blows");
            document.getElementById("myCanvas").style.border= "2px solid black";
            house.clearRect(0,0,300,300)
        };
    }