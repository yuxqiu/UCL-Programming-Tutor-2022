var x = 1;

// global scope
function f() {
    var x = 2;
    // function scope
    function ff() {
        console.log(x);
    }
    ff();
}

function g() {
    // it will be 1 based on lexical scoping
    console.log(x);
}

// prefer let over var
function strange() {
    // console.log(does_not_exist);
    var does_not_exist = 1;
    console.log(does_not_exist)
}

strange();