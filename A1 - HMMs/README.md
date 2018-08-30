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
>

> **Question 5:** Howmany values are stored in the matrices <img src="https://latex.codecogs.com/gif.latex?\delta"  title="" /> and <img src="https://latex.codecogs.com/gif.latex?\delta^{idx}"  title="" /> respectively?<br />
>**Answer**<br />
>They have the same size, given by the number of observations and the number of states. so they are both <img src="https://latex.codecogs.com/gif.latex?N\times%20T"  title="" />.

> **Question 6:** Why we do we need to divide by the sum over the final <img src="https://latex.codecogs.com/gif.latex?\alpha"  title="" /> values for the di-gamma
function?<br />
>**Answer**<br />
>

> **Question 7:** Train an HMM with the same parameter dimensions as above, i.e. <img src="https://latex.codecogs.com/gif.latex?\textbf{A}"  title="" /> should be a 3 times 3 matrix, etc. Initialize your algorithm with the following matrices:<br /><br /><img src="https://latex.codecogs.com/gif.latex?\textbf{A}=\begin{pmatrix}0.54&0.26&0.2\\0.19&0.53&0.28\\0.22&0.18&0.6\end{pmatrix}" title="" /> <img src="https://latex.codecogs.com/gif.latex?\textbf{B}=\begin{pmatrix}0.5&0.2&0.11&0.19\\0.22&0.28&0.23&0.27\\0.19&0.21&0.15&0.45\end{pmatrix}" title="" /> <img src="https://latex.codecogs.com/gif.latex?\pi=\begin{pmatrix}0.3&0.2&0.5\end{pmatrix}" title="" /><br /><br />Does the algorithm converge? How many observations do you need for the algorithm to converge? How can you define convergence?<br />
> **Answer**<br />

> **Question 8:** Train an HMM with the same parameter dimensions as above, i.e. A is a 3x3 matrix etc. The initialization is left up to you.<br />How close do you get to the parameters above, i.e. how close do you get to the generating parameters in Eq. 3.1? What is the problem when it comes to estimating the distance between these matrices? How can you solve these issues?
> **Answer**<br />

> **Question 9:** Train an HMM with different numbers of hidden states. What happens if you use more or less than 3 hidden states? Why?<br />Are three hidden states and four observations the best choice? If not, why? How can you determine the optimal setting? How does this depend on the amount of data you have?
> **Answer**<br />

> **Question 10:** Initialize your Baum-Welch algorithm with a uniform distribution. How does this
effect the learning?<br />Initialize your Baum-Welch algorithm with a diagonal A matrix and <img src="https://latex.codecogs.com/gif.latex?\pi&space;=&space;\begin{bmatrix}&space;0,&space;0,&space;1&space;\end{bmatrix}"  title="" />. How does this effect the learning?<br />Initialize your Baum-Welch algorithm with a matrices that are close to the solution. How does this effect the learning?
> **Answer**<br />
