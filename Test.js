<!DOCTYPE html>
<html ng-app="">
<head>
    <style>
        #diagramContainer {
            padding: 20px;
            width:auto; height:800px;
            border: 1px solid gray;
        }
        
        .item {
            position: absolute;
            height:80px; width: 80px;
            border: 1px solid blue;
            
        }
    </style>

    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    

</head>
<body>
    
    
    <!-- Modal -->
    <div class="modal fade" id="myModal" role="dialog">
        <div class="modal-dialog">
        
            <!-- Modal content-->
            <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal">&times;</button>
                <h4 class="modal-title">Modal Header</h4>
            </div>

            <div class="modal-body">
                
                Operand 1 :<br>
                <input type="text" id="txtOperand1" placeholder="Enter Operand 1 value" />                
                <br>
                Operand 2 :<br>
                <input type="text" id="txtOperand2" placeholder="Enter Operand 2 value" />
                <br>
                Operation :
                <br>
                <select id='operations'>
                        <option value="GR">Greater Than</option>
                        <option value="LS">Less Than</option>
                        <option value="mercedes">Equals</option>
                </select>
                <br>
                Node : 
                <br>
                <select id='sourceNode' ></select>
            </div>

            <div class="modal-footer">
                <button type="button" id='btnCreateRule'
                class="btn btn-primary" 
                    id="btnAddRule">Add rule</button> 
                <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
            </div>
            </div>
            
        </div>
    </div>
    <!-- Modal -->
    <div>
        <div id="diagramContainer">
            <div id="node0" class="item">Start</div>                
        </div>
        
        <input id='txtTitle' />
        <button id='btnAddNode' >Add Node</button>   
        <div>
            
            <!-- data-toggle="modal" data-target="#myModal" -->
            <button id='btnOpenRuleDesign' type="button" class="btn btn-info btn-lg" >Add Rules</button>
        </div>
        
    </div>
    

    <p><a href="https://github.com/suniljadhav709/">Visit Sunil Jadhav</a> to keep yourself updated.</p>
    <script src="./jquery.min.js"></script>
    <!-- <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script> -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    <script src="./jquery-ui.min.js"></script>
    <script src="./jquery.jsPlumb-1.4.1-all-min.js"></script>
    <script>
        
        jsPlumb.ready(function() {
            var counter = 1;
            var node_collection = [{
                id : 0,
                title : 'start',
                name : 'node0'
            }];

            // $('.item').on('click', function(){
            //     alert('id : ' + this.id);
            // })
            
            $('#btnOpenRuleDesign').on('click', function(){
                //alert('sdsds');
                $.each(node_collection, function (i, item) {
                    $('#sourceNode').append($('<option>', { 
                        value: item.id,
                        text : item.title 
                    }));
                });
                $('#myModal').modal('show');
            })
        
            $('#btnCreateRule').on('click', function(){
                var operand1 = $('#txtOperand1').val();
                var operand2 = $('#txtOperand2').val();
                var op_select = $('#operations').val();
                var node_index = $('#sourceNode').val();

                alert('Operand 1 : ' + operand1 + '\n' + 
                    'Operand 2 : ' + operand2 + '\n' +
                    'Operation : ' + op_select);

                createNode();
            });
            function createNode(){
                var new_node  = document.createElement('div');
                new_node.className = 'item';
                new_node.id = 'node'+counter;
                
                new_node.innerHTML = $('#txtTitle').val() + '\n' + 'id is ' + counter ;
                var container = document.getElementById('diagramContainer');
                container.appendChild(new_node);
                jsPlumb.draggable(new_node.id);
                //$(new_node.id).on('click' , node_clicked(new_node));
                new_node.on('click', function(){
                    alert('id : ' + this.id);
                });
                counter++;
            }
            $('#btnAddNode').on('click', function(){
                
                var new_node  = document.createElement('div');
                new_node.className = 'item';
                new_node.id = 'node'+counter;
                
                new_node.innerHTML = $('#txtTitle').val() + '\n' + 'id is ' + counter ;
                var container = document.getElementById('diagramContainer');
                container.appendChild(new_node);
                jsPlumb.draggable(new_node.id);
                //$(new_node.id).on('click' , node_clicked(new_node));
                new_node.on('click', function(){
                    alert('id : ' + this.id);
                });
                counter++;
            })
            
            $('#btnConnect').on('click', function(){
                var source_node = 'node' + $('#txtSource').val();
                var destination_node = 'node' + $('#txtDestination').val();
                alert('Gonna connect ' + source_node + ' with ' + destination_node);
                addConnection(source_node, destination_node);
            })

            function addConnection(source_name, destination_name ){
                jsPlumb.connect({
                connector: ["Flowchart"],
                source:source_name,
                anchors : ["Bottom", "Top"],
                target: destination_name,
                endpoint:"Blank",
                paintStyle:{ strokeStyle:"lightgray", lineWidth:1 },
                endpointStyle:{ fillStyle:"lightgray", outlineColor:"gray" },
                overlays:[ 
                    ["Arrow" , { width:12, length:12, location:0.67 }]
                ]
            });
            }

            // jsPlumb.connect({
            //     connector: ["Flowchart"],
            //     source:"item_left",
            //     anchors : ["Bottom", "Top"],
            //     target:"item_right",
            //     endpoint:"Blank",
            //     paintStyle:{ strokeStyle:"lightgray", lineWidth:1 },
            //     endpointStyle:{ fillStyle:"lightgray", outlineColor:"gray" },
            //     overlays:[ 
            //         ["Arrow" , { width:12, length:12, location:0.67 }]
            //     ]
            // });
            
            jsPlumb.draggable("node0");
            
        });
    </script> 

</body>
</html>
