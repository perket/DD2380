# A1: HMMs

### Questions

> **Question 1:** This problem can be formulated in matrix form. Please specify the initial probability vector <img src="https://latex.codecogs.com/gif.latex?\pi"  title="" />, the transition probability matrix <img src="https://latex.codecogs.com/gif.latex?\textbf{A}"  title="" /> and the observation probability matrix <img src="https://latex.codecogs.com/gif.latex?\textbf{B}"  title="" />.<br />
> **Answer**<br />
> <img src="https://latex.codecogs.com/gif.latex?\pi&space;=&space;\begin{bmatrix}&space;.5&space;&&space;.5&space;\end{bmatrix}"  title="" /><br />
> <img src="https://latex.codecogs.com/gif.latex?\textbf{A}&space;=&space;\begin{bmatrix}&space;.5&space;&&space;.5\\&space;.5&space;&&space;.5&space;\end{bmatrix}"  title="" /><br />
> <img src="https://latex.codecogs.com/gif.latex?\textbf{B}&space;=&space;\begin{bmatrix}&space;.9&space;&&space;.1\\&space;.5&space;&&space;.5&space;\end{bmatrix}"  title="" />

> **Question 2:** What is the result of this operation? <br />
> **Answer**<br />
> <img src="https://latex.codecogs.com/gif.latex?\textbf{A}\cdot\pi=\begin{bmatrix}.5&.5\end{bmatrix}"  title="" /><br />

> **Question 3:** What is the result of this operation? <br />
> **Answer**<br />
><img src="https://latex.codecogs.com/gif.latex?\textbf{B}\cdot(\textbf{A}\cdot\pi)=\begin{bmatrix}.7&.3\end{bmatrix}" title="" /><br />

> **Question 4:** Why is it valid to substitute <img src="https://latex.codecogs.com/gif.latex?\textbf{O}_{1:t}=\textbf{o}_{1:t}" title="" /> with <img src="https://latex.codecogs.com/gif.latex?\textbf{O}_{t}=\textbf{o}_{t}" title="" /> for when we condition on the state <img src="https://latex.codecogs.com/gif.latex?\textbf{X}_{t}=\textbf{x}_{i}" title="" />?<br />
> **Answer**<br />
><img src="https://latex.codecogs.com/gif.latex?\textbf{O}_t" title="" /> is conditionally independent from <img src="https://latex.codecogs.com/gif.latex?\textbf{O}_{1:(t-1)}" title="" /> given <img src="https://latex.codecogs.com/gif.latex?\textbf{X}_t" title="" /> and therefore all we need to know about <img src="https://latex.codecogs.com/gif.latex?\textbf{O}_t" title="" /> is already covered by <img src="https://latex.codecogs.com/gif.latex?\textbf{X}_t=\textbf{x}_i" title="" />

> **Question 5:** Howmany values are stored in the matrices <img src="https://latex.codecogs.com/gif.latex?\delta"  title="" /> and <img src="https://latex.codecogs.com/gif.latex?\delta^{idx}"  title="" /> respectively?<br />
>**Answer**<br />
>They have the same size, given by the number of observations and the number of states. so they are both <img src="https://latex.codecogs.com/gif.latex?N\times%20T"  title="" />.

> **Question 6:** Why we do we need to divide by the sum over the final <img src="https://latex.codecogs.com/gif.latex?\alpha"  title="" /> values for the di-gamma function?<br />
>**Answer**<br />
> Bayes' theorem<br />
> <img src="https://latex.codecogs.com/gif.latex?P(A|B)=\frac{P(B|A)P(A)}{P(B)}=\frac{P(\textbf{O}_{1:T}=\textbf{o}_{1:T}|\textbf{X}_t=\textbf{x}_i,\textbf{X}_{t+1}=\textbf{x}_j)P(\textbf{X}_t=\textbf{x}_i,\textbf{X}_{t+1}=\textbf{x}_j)}{P(\textbf{O}_{1:T}=\textbf{o}_{1:T})}"  title="" /><br />
>From 2.14 and 2.15 we can see that<br />
><img src="https://latex.codecogs.com/gif.latex?P(\textbf{O}_{1:T}=\textbf{o}_{1:T})=\sum_{j=1}^{N}\alpha_T(j)"  title="" /><br />
>Which is the denominator we are looking for.

> **Question 7:** Train an HMM with the same parameter dimensions as above, i.e. <img src="https://latex.codecogs.com/gif.latex?\textbf{A}"  title="" /> should be a 3 times 3 matrix, etc. Initialize your algorithm with the following matrices:<br /><br /><img src="https://latex.codecogs.com/gif.latex?\textbf{A}=\begin{pmatrix}0.54&0.26&0.2\\0.19&0.53&0.28\\0.22&0.18&0.6\end{pmatrix}" title="" /> <img src="https://latex.codecogs.com/gif.latex?\textbf{B}=\begin{pmatrix}0.5&0.2&0.11&0.19\\0.22&0.28&0.23&0.27\\0.19&0.21&0.15&0.45\end{pmatrix}" title="" /> <img src="https://latex.codecogs.com/gif.latex?\pi=\begin{pmatrix}0.3&0.2&0.5\end{pmatrix}" title="" /><br /><br />Does the algorithm converge? How many observations do you need for the algorithm to converge? How can you define convergence?<br />
> **Answer**<br />
> Yes!<br />
> Somewhere around 175, is where it stops improving while learning.<br />
> We say that the HMM converges if <img src="https://latex.codecogs.com/gif.latex?a_{i}^{*}" title="" /> gets closer to <img src="https://latex.codecogs.com/gif.latex?a_{i}" title="" /> and <img src="https://latex.codecogs.com/gif.latex?b_{i}^{*}" title="" /> gets closer to <img src="https://latex.codecogs.com/gif.latex?b_{i}" title="" /> for each training iteration. In other words, if <img src="https://latex.codecogs.com/gif.latex?\textbf{A}^{*}" title="" /> and <img src="https://latex.codecogs.com/gif.latex?\textbf{B}^{*}" title="" /> become more and more similar to <img src="https://latex.codecogs.com/gif.latex?\textbf{A}" title="" /> and <img src="https://latex.codecogs.com/gif.latex?\textbf{B}" title="" />

> **Question 8:** Train an HMM with the same parameter dimensions as above, i.e. A is a 3x3 matrix etc. The initialization is left up to you.<br />How close do you get to the parameters above, i.e. how close do you get to the generating parameters in Eq. 3.1? What is the problem when it comes to estimating the distance between these matrices? How can you solve these issues?
> **Answer**<br />
> Using the Frobenius norm, my initial distances was 1.12441 for <img src="https://latex.codecogs.com/gif.latex?\textbf{A}" title="" /> and 0.655744 for <img src="https://latex.codecogs.com/gif.latex?\textbf{B}" title="" />. After training the distances where 0.65148 for <img src="https://latex.codecogs.com/gif.latex?\textbf{A}" title="" /> and 0.735848 for <img src="https://latex.codecogs.com/gif.latex?\textbf{B}" title="" />. So a significant improvement on <img src="https://latex.codecogs.com/gif.latex?\textbf{A}" title="" /> and a small deterioration on <img src="https://latex.codecogs.com/gif.latex?\textbf{B}" title="" />.<br />
>There is some ambiguity to what exactly we wanna measure. To matrices can cross each other and we could say that the distance therefore say that the distance is 0. In this case it is more useful to measure the distance between each element of the matrices and look at a combined value of all the distances. Frobenius norm is one way to do this, but there are many others.


> **Question 9:** Train an HMM with different numbers of hidden states. What happens if you use more or less than 3 hidden states? Why?<br />Are three hidden states and four observations the best choice? If not, why? How can you determine the optimal setting? How does this depend on the amount of data you have?
> **Answer**<br />
> More states gives longer runtime both when using 1000 and 10000 data sequences. Fewer states runs faster when using 10000 sequences but needs more iterations when running with 1000 sequences.<br />
> Overfitting may be a problem when using too many states, but too few may not be able to hold enough information for the HMM to work.<br />
> Strangely <img src="https://latex.codecogs.com/gif.latex?\pi" title="" /> changes when using 1000 or 10000 data sequences, using 2, 3 and 4 states. This should not happen and might indicate that the optimal number of states is larger than 3.

> **Question 10:** Initialize your Baum-Welch algorithm with a uniform distribution. How does this
effect the learning?<br />Initialize your Baum-Welch algorithm with a diagonal A matrix and <img src="https://latex.codecogs.com/gif.latex?\pi&space;=&space;\begin{bmatrix}&space;0,&space;0,&space;1&space;\end{bmatrix}"  title="" />. How does this effect the learning?<br />Initialize your Baum-Welch algorithm with a matrices that are close to the solution. How does this effect the learning?
> **Answer**<br />
> Uniformly distributed matrices are not able to learn. <img src="https://latex.codecogs.com/gif.latex?\textbf{A}" title="" /> stays the same and <img src="https://latex.codecogs.com/gif.latex?\textbf{B}" title="" /> gets marginally better. Only runs for 3 iterations.
> Using diagonal matrices and <img src="https://latex.codecogs.com/gif.latex?\pi&space;=&space;\begin{bmatrix}&space;0,&space;0,&space;1&space;\end{bmatrix}"  title="" /> the HMM is not able to learn and produces matrices filled with NaN.
> When using matrices close to the solution it trains for 1777 iterations and the result is worse than the initial settings.
