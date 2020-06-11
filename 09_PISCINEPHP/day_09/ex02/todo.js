var ft_list;
var cookie = [];

window.onload = function () {
    document.querySelector("#new").addEventListener("click", newTodo);
    ft_list = document.querySelector("#ft_list");
    var tmp = document.cookie;
    var regex = /^todo=/g;
    if (tmp) {
        cookie = decodeURIComponent(tmp).split(';');
        for (var i = 0; i < cookie.length ; i++) {
            if (cookie[i].match(regex) != null) {
                var cook = cookie[i];
                break ;
            }
        }
        if (cook) {
            cook = cook.substring(5, cook.length);
            cook = cook.split(',');
            cook.forEach(function(e) {
                if (e !== "")
                    addTodo(e);
            });
        }
    }
};

window.onunload = function () {
    var todo = ft_list.children;
    var newCookie = [];
    for (var i = 0; i < todo.length; i++)
        newCookie.unshift(todo[i].innerHTML);
    var cook = encodeURIComponent(newCookie);
    var date = new Date;
	date.setMonth(date.getMonth()+1); // expire dans un mois
	date = date.toUTCString();
    document.cookie = "todo=" + cook + "; " + date;
};

function newTodo(){
    var todo = prompt("What should I remember?", '');
    if (todo !== '') {
        addTodo(todo)
    }
}

function addTodo(todo){
    var div = document.createElement("div");
    div.innerHTML = todo;
    div.addEventListener("click", deleteTodo);
    ft_list.insertBefore(div, ft_list.firstChild);
}

function deleteTodo(){
    if (confirm("Are you sure you want to delete this one?")){
        this.parentElement.removeChild(this);
    }
}