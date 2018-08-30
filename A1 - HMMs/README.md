# A1: HMMs

### Questions

> **Question 1:** This problem can be formulated in matrix form. Please specify the initial probability vector <img src="https://latex.codecogs.com/gif.latex?\pi"  title="" />, the transition probability matrix <img src="https://latex.codecogs.com/gif.latex?\textbf{A}"  title="" /> and the observation probability matrix <img src="https://latex.codecogs.com/gif.latex?\textbf{B}"  title="" />.<br />
> **Answer**
> <img src="https://latex.codecogs.com/gif.latex?\pi&space;=&space;\begin{bmatrix}&space;.5&space;&&space;.5&space;\end{bmatrix}"  title="" /><br />
> <img src="https://latex.codecogs.com/gif.latex?\textbf{A}&space;=&space;\begin{bmatrix}&space;.5&space;&&space;.5\\&space;.5&space;&&space;.5&space;\end{bmatrix}"  title="" /><br />
> <img src="https://latex.codecogs.com/gif.latex?\textbf{B}&space;=&space;\begin{bmatrix}&space;.9&space;&&space;.1\\&space;.5&space;&&space;.5&space;\end{bmatrix}"  title="" />

> **Question 2:** What is the result of this operation? <br />
> **Answer**
> <img src="https://latex.codecogs.com/gif.latex?\textbf{A}\cdot\pi=\begin{bmatrix}.5&.5\end{bmatrix}"  title="" /><br />

> **Question 3:** What is the result of this operation? <br />
> **Answer**
><img src="https://latex.codecogs.com/gif.latex?\textbf{B}\cdot(\textbf{A}\cdot\pi)=\begin{bmatrix}.7&.3\end{bmatrix}" title="" /><br />

> **Question 4:** Why is it valid to substitute <img src="https://latex.codecogs.com/gif.latex?\textbf{O}_{1:t}=\textbf{o}_{1:t}" title="" /> with <img src="https://latex.codecogs.com/gif.latex?\textbf{O}_{t}=\textbf{o}_{t}" title="" /> for when we condition on the state <img src="https://latex.codecogs.com/gif.latex?\textbf{X}_{t}=\textbf{x}_{i}" title="" />?<br />
> **Answer**
>

> **Question 5:** Howmany values are stored in the matrices <img src="https://latex.codecogs.com/gif.latex?\delta"  title="" /> and <img src="https://latex.codecogs.com/gif.latex?\delta^{idx}"  title="" /> respectively?<br />
>**Answer**
>They have the same size, given by the number of observations and the number of states. so they are both <img src="https://latex.codecogs.com/gif.latex?N\times T"  title="" />.
