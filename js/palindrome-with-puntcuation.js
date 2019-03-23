let a = "Madam, I'm Adam";

let AllPunctString = " \n.,:;…!?-–—‚‘„“‹›«»\"`'()[]{}";

function is_palindrome(a)
{ return ( a.length < 2 || 
	  (AllPunctString.includes(a[0]) && is_palindrome(a.substr(1))) ||
	  (AllPunctString.includes(a[a.length-1]) && is_palindrome(a.substr(0,a.length-2))) ||
	  (a[0].toLowerCase() == a[a.length-1].toLowerCase() && is_palindrome (a.substr(1,a.length-2))) );
}
    
console.log(is_palindrome(a))
