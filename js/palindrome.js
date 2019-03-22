a = "abba"

function is_palindrome(a) {
    if (a.length < 2) { return true; } 
    return (a[0] == a[a.length-1] && is_palindrome (a.substr(1,a.length-2)))
}
    
console.log(is_palindrome(a))
