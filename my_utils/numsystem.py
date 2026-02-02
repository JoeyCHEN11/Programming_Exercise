from collections import deque

# convert one digit to decimal number
def toDecDigit(d: str) -> int:
    if d.isdigit():
        return ord(d) - ord('0');
    elif not d.isalpha():
        return '$';
    else:
        return 10 + ord(d.upper()) - ord('A');


# convert decimal number to other base digit
def toBaseDigit(d: int) -> str:
    if d >= 0 and d <= 9:
        return chr(ord('0') + d)
    # cout<<"large"<<endl;
    return chr(ord('A') + d - 10);


# any base to decimal num
def baseToDecimal(num: str, base: int) -> int:
    ans = 0;
    for c in num:
        ans *= base;
        ans += toDecDigit(c);
    return ans;

    """_summary_
    convert decimal number to any base
    Returns:
        str: converted number
    """
def decimalToBase(decNum: int, base: int) -> str:
    ans = deque();
    digit = 0
    # //unsigned long long num = 0; //strtoll(decNum, NULL, 10);

    while decNum:
        digit = decNum % base;
        # //cout<<toBaseDigit(digit)<<endl;
        ans.appendleft(toBaseDigit(digit));
        decNum //= base;
    
    return ''.join(ans);


# /**
#  * @brief convert base s num to base t
#  * 
#  * @param num 
#  * @param b1 
#  * @param b2 
#  * @return string 
#  */
def baseConvert(num: str, s: int, t: int) -> str:
    return decimalToBase(baseToDecimal(num, s), t)


if __name__ == '__main__':
    print(baseToDecimal("D0000000", 16))
    print(decimalToBase(100000, 2))
    print(0b11000011010100000)
    print(baseConvert("ed3a", 16, 10))

