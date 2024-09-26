In the code in Question 6 , the output value of x is 30. 
The reason is that,, in the ternary operator the format is ( condition ) ? (value if true ): (value if false)
So reviewing the question , first we get  5 > 8, which is false, meaning that the true part (10) is skipped and we move onto the expression after the ' : '
Next, we have the expression 1 != 2 < 5. Due to  precedence, the expression is evaluated as follows: 
first 2 < 5 is solved which gives us 1 
then 1 != 1 which gives us 0 .
meaning that this expression is also false, hence the true part (20) after the ? is skipped and we end up with the value of 30 for x.
