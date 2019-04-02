var a = [1,1,2,3,5,8,13,21];

// Loops

var i = 0, sum = 0;
while (i < a.length) { sum += a[i]; i++; }
for (i = 0, prod = 1; i < a.length; i +=2) { prod *= a[i]; }

console.log(sum, prod);

// Array methods

sum = a.reduce(function(total, value) { return total+value; });
prod = a.reduce(function(total, value, index) { return (index % 2 == 0) ? total*value : total; });

console.log(sum, prod);
