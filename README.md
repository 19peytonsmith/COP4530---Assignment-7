<div id="kl_assignments" class="">
<h3 class="">
<i class="icon-assignment" aria-hidden="true"></i>Module Assignments</h3>
<p><span><strong>Objectives:&nbsp;</strong> Practice selecting and making use of appropriate&nbsp; STL containers to perform tasks.&nbsp;&nbsp;</span></p>
<p><span><strong>Statement of Work:</strong> Implement a program that collects the statistics of word, number, and character usage in a file<br>(redirected as the standard input).</span></p>
<p><strong>Requirements:&nbsp;</strong></p>
<p><span>1. Write a program that will read input (from standard input) until end of input is reached<br>("end of file"), which will count the number of times each word, number, and character<br>appears in the input.</span></p>
<ul>
<li><span>A word is defined as a consecutive sequence one or more letters ('a'..'z' or 'A'..'Z').<br>Words are not case insensitive ("AA", "Aa", "aA", and "aa" are the same).</span></li>
<li><span>A number is defined as any consecutive sequence of digits ('0'..'9').</span></li>
<li><span>Note that both words and numbers can be of length of 1, that is, contain one letter<br>or one digit, respectively.</span></li>
<li><span>Different sequences represent different numbers. For example, number "001" is<br>different from number "1".</span></li>
<li><span>Words are separated by any non-letter characters.</span></li>
<li><span>Characters are all printable characters plus the space, tab ‘\t’ , and new line<br>‘\n’.</span></li>
<li><span>Numbers are separated by any non-digit characters. We will not complicate this<br>by having you distinguish between integers and floating point numbers with<br>decimal places.</span></li>
<li>
<span><span>In the example below there are 88 characters.&nbsp; There is one number (123), there are 17 words, All the words appear the same amount of time but "two" appears first, there are 31 unique characters and the blank appears the most followed by the letter "o" , "d", "r", "a", "e", "l", "n", "s", and "t"&nbsp; &nbsp;</span></span>
<div><em><strong>Two roads diverged in a yellow wood, And sorry I could not travel both for 123 (days)&nbsp;</strong></em></div>
</li>
</ul>
<p><strong>Output Specifications:&nbsp;</strong></p>
<ul>
<li>Your program should track the number of times each word, number, and character<br>appears.</li>
<li>The program should then output the ten most used characters, the ten most used<br>numbers, and the ten most used words, along with the number of times each of<br>these characters/numbers/words are used.</li>
<li>Since words are case insensitive, the program should only store and output the words in<br>lower case.</li>
<li>The characters, numbers and words should be printed in descending order based<br>on the number of times they are used.</li>
<li>Breaking ties (for the "Top Tens"):
<ul>
<li>When two characters occur the same number of times, the character with<br>the smaller ASCII value should be considered as being used more<br>frequently.</li>
<li>When two words (or numbers) occur the same number of times, the word<br>(or number) that occurs earlier in the input should be considered as being<br>used more frequently.</li>
</ul>
</li>
</ul>
<p>2. An example executable code of the program is provided to you (see below). You should<br>make the outputs of your program match this sample executable. When printing<br>characters, use<em> '\t'</em> for tab and <em>'\n'</em> for newline. and <em>‘space’ </em>for a space or blank<br>character. All other characters should be printed normally.</p>
<p>3. Write a makefile for your project that compiles an executable called <em>proj6.x</em></p>
<p>4. Make use of <em><strong>any appropriate C++ STL</strong></em> containers and algorithms. You should also use<br>C++ string class instead of default c-strings.&nbsp; Note that you should select whatever container(s) will make your program's algorithm the most efficient in terms of growth rate ( i.e. "Big-O" complexity analysis).&nbsp;&nbsp;</p>
<p>5. In a file called <em>analysis.txt</em>, write up your analysis of the complexity analysis of the<br>important algorithms and procedures in your program. Note that your analyses will be<br>based on not only the code YOU write, but also on the STL containers you choose for<br>managing your data. Your analyses need to include analysis of at least (but not limited to)<br>each of these necessary tasks:</p>
<ul>
<li>Reading the input set</li>
<li>Storing the characters / words / numbers in your chosen containers, and setting<br>their tracking values</li>
<li>Looking up the final tracking info on your character / word / number frequencies</li>
<li>Deciding on (and accessing for output) your "Top Ten" most frequent list for each<br>case</li>
<li>Any other important algorithm/tasks you perform to complete the job</li>
</ul>
<p>6. While not a program requirement for submission, it is recommended that you verify your<br>analysis of your program elements by testing larger input sets and also by measuring the<br>actual run time speed of those test runs. You can do this in a program easily by using<br>the <em>ctime</em> library and capturing the returns from the <em>clock()</em> function before and after an<br>algorithm, then subtract the two clock times to see the difference. Convert the number to<br>seconds by dividing by the constant <em>CLOCKS_PER_SEC.</em> On linprog, you can look up more<br>details at the manual page for clock (<em>man clock</em>).</p>
<p>Submission:&nbsp;</p>
<p>Tar all of your source code, as well as your <em>makefile </em>and your <em>analysis.tx</em>t file, into a single tar<br>archive and submit online via blackboard, using the Assignment 6 link.<br>Your tar file should be named in this format, all lowercase:</p>
<p><br>lastname_firstname_p7.tar</p>
<p>Example: My tar file would be: gaitros_davd_proj7.tar</p>
<p><br>Verify your file has been submitted properly.</p>
<p><br>Note that in addition to the provided test cases, we will also test your program using additional<br>test files. Your program must be able to pass all the test cases in order to obtain a full score for<br>the corresponding components. Part of the grading will take your choice of STL containers and<br>your complexity analyses into account, and testing will involve some larger sets of inputs</p>
</div>
</div>
</div>
