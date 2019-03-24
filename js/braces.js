function is_balanced(a)
{ if (a == "") { return true; }
//  console.log("a:", a);
  let len = a.length;
  if (len % 2 == 1) { return false; } 
  if (!(a.startsWith("(") && a.endsWith(")")))
  { // console.log("deadend"); 
    return false; }
  if (is_balanced(a.substr(1,len-2))) { return true; } 
  let n = 0;
  let m = 0;
  while (!(n == -1))
  { m = a.indexOf(")(", n+1);
    if (!(m == -1))
    { // console.log("tmp:", a, m, a.substr(0,m+1), a.substr(m+1,len-m-1), "!");
      if (is_balanced(a.substr(0,m+1)) && is_balanced(a.substr(m+1,len-m-1)))
      { return true; }
    }
    n = m;
  }
  return false;
}


console.log(is_balanced("()"))
console.log(is_balanced("(((())))"))
console.log(is_balanced("()()()()"))
console.log(is_balanced("(()())(()())"))
console.log(is_balanced("((()())())"))
console.log(is_balanced(")("))
console.log(is_balanced("((())"))
console.log(is_balanced("(()))((())"))


   
