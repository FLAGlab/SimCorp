# Evaluation

We evaluate our program similitude analysis in two stages. First, we use algorithms from known domains to evaluate their semantic similitude. Second, we focus on the evaluation of our approach using a new corpus for program similitude analysis, to evaluate our algorithm on larger codebases. The programs in the corpus are divided in 5 domains, including for each domain implementations that are alike and that are structurally different --that is, differ further than small deltas, but still provide the same behavior.

## Evaluation Environment

To execute all the evaluation scenarios we use a Intel core i5-5257U processor with 8GB RAM running Ubuntu 18.04.2 LTS. Our evaluation uses version 3.3 of LLVM and C++11.

## Effectiveness of Code Clone Detection

To start the evaluation of our proposed algorithm, we validate its effectiveness by analyzing the performance of our algorithm with a small example from well-known domains. Then, We validate the effectiveness of our approach with respect to the state-of-the-art, using the BigClone benchmark focusing on Type-4 code clone detection.

### Known Domains

As explained before, our similitude evaluation does not look to
detect small semantic changes between program deltas. Rather, we are
interested in a metric for similitude for algorithms within a class of
algorithms with the same pre- and post-conditions. That is, we want
to analyze programs that can have different characteristics
(e.g., black-box behavior).

#### Experiment Setup

We first evaluate our tool comparing 10 programs of well-known
algorithms from three different domains:
sorting (4 programs), search (2 programs), and
aggregation (4 programs).

**Table 1.** Characterization of the knwon domains data set

| Algorithm  | LoC | Loops  | Conditionals | Parameters | Data structures | CFG nodes |
|----------|--------|--------|--------|--------|--------|--------|
| bubble sort | 19 | 2 | 1 | array | - | 9 |
| gnone sort | 16 | 1 | 1 | array | - | 8 |
| merge sort  | 54 | 5 | 2 | array | - | 27 |
| quick sort  | 36 | 2 | 2 | array | stack | 13|
| binary search | 16 | 1 | 2 | array | - | 9 |
| linear search | 10 | 1 | 1 | array | - | 8 |
| min | 10 | 1 | 1 | array | - | 9 |
| max | 10 | 1 | 1 | array | - | 9 |
| sum | 7 | 1 | 0 | array | - | 4 |
| sum odd | 9 | 1 | 1 | array | - | 6 |

The previous table shows the algorithms used as representative of each
application domain, describing the algorithms' complexity and
structure by their LoC, and the loops and conditionals used in
the implementation. Additionally, we describe the input parameters the
used data structures, and the nodes of the generated CFG.
We can see from the table that most of the algorithms have a similar
structure, as they iterate over an array to compute their
functionality, usually described by a set of
operations within a conditional. Our hypothesis for this evaluation
is that the algorithms with a closest structure should be more similar
to each other, than to the other algorithms.

#### Results

Figure 1 shows the evaluation of the three application
domains using our algorithm. From the figure, it is possible to see
that the algorithms are not clustered as initially expected.
Nonetheless, the observed clusters are close to our hypothesis. The
difference in the clusters yields from the structure of the
algorithms, as this metric takes precedence over the behavior metric.
A first cluster (to the top left of the figure) is composed of the
aggregation algorithms and the `linear` search algorithm. These
algorithms all have the same structure, a loop over the input array
parameter with an inner `if` condition to evaluate each array element
with respect to the algorithm's goal. This similarity can be observed
too from their corresponding CFG (Figures 1
and 2 in the paper), confirming that indeed the algorithms are  
structurally related. The exception of this cluster is the `sum`
algorithm, which does not have the conditional, this marks a
difference in the comparison. However, its behavior is still closest
to the other aggregation and `linear`search algorithms than to
any other algorithm from the other domains.
The second cluster, groups together the `bubble` and
`gnone` sorting algorithms with `binary` search (towards
the bottom of the figure). In line with our hypothesis, the sorting
algorithms are close together.
`binary` search is close to `bubble` sort given the
similarity of the outer most loop in both algorithms. The conditionals
in both algorithms also present a similar behavior that adds up to the
similarity score.
The third cluster (on the right of the figure) contains the two
different algorithms of the data set `merge` and `quick`
sort. These two algorithms are not similar with each other or any of
the other algorithms. `quick` sort differs from all algorithms
as it uses an additional data structure, a stack, to order the array
iteratively. `merge` sort, differs from the other algorithms as
the structure of the loops is quite different from the other
algorithms, generating more nodes when building the CFG. The
separation of the algorithms in this cluster form the other algorithms
is confirmed by the similarity matrix shown in
Table 2.

![Results](img/similarity-basic-NORMALIZED-NODE-SYM.png "Known domain results")
**Figure 1.** Clustering of algorithms from the known domains

Table 2 shows the 10x10
similarity matrix for the comparison between all the programs of the
known domains. In the table, the diagonal (in bold) corresponds to the
comparison of the algorithm with itself, which is the highest
similarity for the algorithm. Therefore, in the table, the closer the
values are to those in the diagonal, the more similar the algorithms.
For example, in the `min` column (where the value in bold,
representing similarity to itself, is 0.6231), the
closest values are those corresponding to `max` 0.6231 as
these two algorithms are semantically the same, and `linear`
(0.6182). In this case, all sorting algorithms have a score
lower than 0.3865, as these algorithms belong to a different domain
and do not support the same pre- and post-conditions.
In the case of `quick` sort, we observe that all values are
bellow 0.3017, which is smaller than half, when compared to the
self-similarity value of 0.6053.

**Table 2.** Similarity matrix for the known algorithms

| | sum | sum_odd | min | linear | quick | binary | merge | bubble | max | gnone |
|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
sum | **0.6475** | 0.3859 | 0.3884 | 0.3837 | 0.1309 | 0.2188 |  0.0824 | 0.2391 | 0.3884 | 0.2748
sum_odd | 0.3859 | **0.6231** | 0.5866 | 0.5817 | 0.2087 | 0.3113 | 0.1158 | 0.3458 | 0.5866 | 0.3951
min | 0.3884 | 0.5866 | **0.6231** | 0.6182 | 0.2005 | 0.3282 | 0.1130 | 0.3457 | 0.6231 | 0.3865
linear | 0.3837 | 0.5817 | 0.6182 | **0.6231** | 0.2026 | 0.3314 | 0.1132 | 0.3471 | 0.6182 | 0.3830
quick | 0.1309 | 0.2087 | 0.2005 | 0.2026 | **0.6053** | 0.2738 | 0.2108 | 0.3017 | 0.2005 | 0.2648
binary | 0.2188 | 0.3113 | 0.3282 | 0.3314 | 0.2738 | **0.6123** | 0.1470 | 0.4191 | 0.3282 | 0.4091
merge | 0.0824 | 0.1158 | 0.1130 | 0.1132 | 0.2108 | 0.1470 | **0.5953** | 0.1707 | 0.1130 | 0.1430
bubble | 0.2391 | 0.3458 | 0.3457 | 0.3471 | 0.3017 | 0.4191 | 0.1707 | **0.6136** | 0.3457 | 0.4243
max | 0.3884 | 0.5866 | 0.6231 | 0.6182 | 0.2005 | 0.3282 | 0.1130 | 0.3457 | **0.6231** | 0.3865
gnone | 0.2748 | 0.3951 | 0.3865 | 0.3830 | 0.2648 | 0.4091 | 0.1430 | 0.4243 | 0.3865 | **0.6129**

The results from Table 2 confirm our hypothesis and
the validity and usefulness of our approach. That is, we are able to
measure the similitude between a set of algorithms in a given domain.
We observe that the algorithms in the search domain are structurally
different, and their similarity score is low with respect to the self
comparison. This suggests the algorithms are indeed diverse, in line
with the motivation of our work. Likewise, in the sorting domain, we
observe `gnone` and `bubble` are closely related, while
`merge` and `quick` are further a part, constituting
different versions of the sorting algorithms. Finally, in the
aggregation domain, we observe indistinguishable features between
`max` and `min`, while `sum` and `sum_odd` are
correctly identified as semantically different to the other two
algorithms in the set.

## Similitude Analysis Corpus

To further evaluate our approach, we analyze more complex programs from different domains, and using different programming styles. With this purpose we build a corpus for the similitude analysis of different programs.

#### Data Corpus Description

Our corpus consists of 566 different C++ programs extracted from the
Codeforces competitive programming online judge. The extracted
programs are solution submissions to five problems (domains).
The problems used present
different implementation characteristics, ranging from simple
straightforward implementations (the difficulty level of the problems
is given by their accompanying letter starting with A as the simplest
problem), to implementations using multiple
functions, requiring to manage complex data structures (e.g., DSU) or
advanced algorithms (e.g., dynamic programming (dp), or computational
geometry). For each of the problems we extracted up to 50 submissions
for each category:
(1) submissions that complete all test cases (OK),
(2) submissions that yield a runtime error (RUNTIME\_ERROR), and
(3) submissions that do not solve the problem
properly (WRONG_ANSWER).
\fref{tab:codeforces} shows the distribution of the data set
classified by solution category, each containing
the average LoC per submission.

**Table 3.** Characterization of the problems in the corpus

| Problem | Domain |  OK  | RUNTIME\_ERROR | WRONG\_ANSWER |
|-----|-----|-----|-------|-----|
558B | implementation | 25 (avg. 28LOC) | 44 (avg. 38LOC) | 50 (avg. 26LOC)
922E | dp | 12 (avg. 27LOC) | 47 (avg. 53LOC) | 49 (avg. 26LOC)
1142C | geometry | 48 (avg. 34LOC) | 25 (avg. 130LOC) | 46 (avg. 31LOC)
1579A | math, strings | 50 (avg. 17LOC) | 21 (avg. 35LOC) | 41 (avg. 19LOC)
1553G | brute force, constructive algorithms, dsu, hashing, number theory |  46 (avg. 55LOC) | 12 (avg. 57LOC) | 50 (avg. 51LOC)

An important characteristic of the data set is that all OK solutions
for a problem are assured to provide the same output to the same
input. However, there is a wide disparity on the
submissions for the other two categories, RUNTIME_ERROR and
WRONG_ANSWER. In these cases, the submitted solutions may variate
from empty programs, to programs close to a solution, to programs that
solve completely different problems.

#### Experiment Design

The similarity evaluation of the programs in our corpus first
computes a similarity matrix containing the similarity score for
every pair of programs compared.
We then use *PCA* to reduce the dimension of
the matrix to two principal components, and plot these components
using the PCA index.
Furthermore, we use the *silhouette coefficient* on
the similarity matrix to evaluate the cohesion and separation of
the clusters per problem. The silhouette score is bounded between
1 and -1, similar programs have a score close to 1, overlapped
clusters have a score close to 0, and dissimilar programs have a
negative score.

We evaluate our algorithm using the *LAV similarity analysis* as a baseline. We take this baseline
for our experiments, as this constitutes the state-of-the-art
analysis for node-based similarity, which is closest to our approach.
Other semantic analysis approaches in the literature are evaluated on small delta variations of the base-code, which are unfit for our purpose.  
Here we focus on the comparison of functionally equivalent programs that satisfy problems' conditions (OK), which we use to identify different implementation
techniques for a specific problem.
In the evaluation we first compare all available programs in the
cluster (each represented by a color in Figures
4 to
11), with the
objective of observing whether our algorithm is capable of
differentiating between the different problem submissions.
We then focus in the comparison by type of submission (OK,
RUNTIME_ERROR, or WRONG_ANSWER) to observe the relevance of
functional equivalence of programs when analyzing their similitude.
Finally, we use our algorithm to identify different implementation
techniques from a given set of submissions for a specific problem.

Note that all programs in our corpus have common a behavior
(e.g., I/O instructions), and therefore have a positive similarity
score. Furthermore, as all the submissions that solve a problem
(i.e., the OK category) have the same black-box behavior, we expect all
solutions to a problem to be clustered. However, while the solutions
to a problem behave the same, the algorithms used can have different
implementations; therefore, we also expect to find sub-clusters for
each problem.
The case of incorrect solutions to the problems is not as well
defined. These solutions may come from quite different algorithms in
terms of the underlying solution strategy, structure, and data
structures used, so not all solutions should be close together.

#### Corpus Results

Our evaluation calculates the similarity of the
different problems from three perspectives. First, we generate the
similarity matrix using the LAV method(labeled ORIGINAL in the figures).
Second, we use our node similarity method to compare the submissions
(labeled ORIGINAL-NODE-SYM in the figures).
Third, we applied the normalization on the node similarity as
described by our approach (labeled NORMALIZED-NODE-SYM in the figures).

Our first experiment compares all 566 available programs, generating
a 566 x 566 similarity matrix. The LAV evaluation in
Figure 4 shows some clustering of the
submissions for each problem (identified by shape and color of the
point in the figure).
In particular, we observe scattering for all problems,
predominately for problem 1579A, and a lot of overlapping between
the submissions for the different problems, for example 922E, 558B,
and 1553G. The overlapping of the clusters is confirmed using the
silhouette score. In the case of the ORIGINAL similarity
measure in Figure 4, we obtained a silhouette score of 0.14.
Using the improved similarity method we obtain a similar clustering as
before, shown in Figure 5, ORIGINAL-NODE-SYM,
with a slight better silhouette score of 0.15. Finally, using our
proposed approach, NORMALIZED-NODE-SYM in
Figure 6, we observe the clusters are less
defined, and the silhouette index decreases to 0.057.

The following figures present the PCA-x and PCA-y components evaluation for all types of submissions for all problems.

![Similarity_Original](img/similarity-ORIGINAL.png)
**Figure 4.** LAV evaluation of the Corpus

![Similarity_Original](img/similarity-ORIGINAL-NODE-SYM.png)
**Figure 5.** LAV normalized evaluation of the Corpus

![Similarity_Original](img/similarity-NORMALIZED-NODE-SYM.png)
**Figure 6.** Our evaluation of the Corpus

This experiment supports our hypothesis that submissions to
the same problem should be clustered together, as shown in the
figures. However, we can attribute the low scores obtained to two
factors. First, the structure of
competitive programming solution programs are very well defined,
always containing a block of code in charge of reading the information
from standard input, a block solving the problem, and a block writing
the solution to standard output. As a consequence, solutions across
problems will have CFG nodes that naturally match, causing them
to increase the similarity score between programs, as seen in the
overlap between the submissions.
Second, as we are comparing all submissions for all problems, we may
take into account solutions to problems that are completely different
from correct solutions (e.g., RUNTIME\_ERROR or WRONG\_ANSWER). This
can cause the sparsity of the solutions for particular problems.

In response to these observations, we then analyze the submissions
of a single type.
When analyzing correct solutions (OK) to the
problems, as shown in the following figures.
Figure 4 shows some clustering for each problem (identified by shape and marker's color in the figure).
The silhouette score is 0.234, but still presents
overlapping and scattering between problems 1579A, 922E, and 1553G.
Using our algorithm, Figure 7
shows a better clustering, %comparable to that of the LAV method, with
a silhouette score of 0.204, and a 3.57x improvement over
the evaluation of all problems. This suggests that, as
problems have behavior equivalence, our approach
significantly improves the similarity metric of the evaluated
programs.
We also analyze all RUNTIME\_ERROR submissions for both
the ORIGINAL method, shown in Figure 9,
and the NORMALIZED-NODE-SYM method, shown in
Figure 10. The silhouette scores for
each method are 0.050 and 0.002, respectively. In this case, as in
the comparison of all problem submissions, we see an overlapped
clustering for our approach, in particular with problems 558B and
1579A. As before, we can attribute the scattering of the submitted
solutions to the general structure of the programs for competitive
programming capturing input/output interaction. The case of these two
problems in particular is that they share a common algorithm which first cycles over the structures and use a conditional to verify the
required property by the problem statement. This pattern, however
incorrect, is repeated in many of the submissions for both problems.

![Similarity_Original](img/similarity-ORIGINAL-OK.png)
**Figure 7.** LAV algorithm for OK submissions

![Similarity_Original](img/similarity-NORMALIZED-NODE-SYM-OK.png)
**Figure 8.** NORMALIZED-NODE-SYM algorithm for OK submissions

![Similarity_Original](img/similarity-ORIGINAL-RUNTIME_ERROR.png)
**Figure 9.** LAV for RUNTIME_ERROR submissions

![Similarity_Original](img/similarity-ORIGINAL-RUNTIME_ERROR.png)
**Figure 10.** Normalized LAV for RUNTIME_ERROR submissions

![Similarity_Original](img/similarity-NORMALIZED-NODE-SYM-RUNTIME_ERROR.png)
**Figure 11.** Our normalized algorithm for RUNTIME_ERROR submissions

Note program scattering can be attributed to
specific algorithms. There might be different
solutions for a given problem, therefore these solutions should not be
as similar to each other, as other solutions with the same algorithmic
principle.

To test this hypothesis, we analyze the correct solutions (OK).
Figure 12 shows the OK submissions for
problem 558B using the ORIGINAL method, with two clusters, showing two
distinctive solutions to this problem. From the figure we see a tight
cluster represented by the solutions using a circle, and a more
scattered clustered represented by the solutions using an orange <span style="color:orange">x</span>. This explains the low
silhouette score of 0.276.
Figure 13 shows the PCA-x PCA-y component evaluation for our NORMALIZED method
evaluating the same problem. Here we too obtain two distinctive
clusters. In this figure we observe that the clusters are less
scattered, explained by a silhouette score of 0.483. As there are
two common solution patterns for the problem, we confirm our algorithm
is effective in finding similar and dissimilar programs for
particular problems with common black-box behavior.

![Similarity_Original](img/similarity-ORIGINAL-558-B-OK.png)
**Figure 12.** LAV algorithm for problem 558B OK

![Similarity_Original](img/similarity-NORMALIZED-NODE-SYM-558-B-OK.png)
**Figure 13.** Our normalized algorithm for problem 558B OK

Similar to this specific analysis,
We use our approach to evaluate
submission types for all the problems in the corpus.
Table 5 presents the silhouette scores for all the
programs in our corpus, with the best scores in bold. It
is important to note, that the silhouette score for a specific
problem, represents the ability of the algorithm to detect different
implementations for the same problem. Not all problems
contain different implementations within the same type of submission.
Identifying such property is valuable for applications domains like
diversity or N-version programming.

**Table 5.** Results of all combinations of problems and submission types.

|Problem | Submission | ORIGINAL | ORIGINAL-NODE-SYM | NORMALIZED-NODE-SYM |
|-----|-----|-----|-----|-----|
| **All** | **All**  | 0.149 | **0.157** | 0.057 |
| **All** | **OK**  | 0.234 | **0.240** | 0.204 |  
| **All** | **WRONG ANSWER**  | 0.207 | **0.210** | 0.101 |
| **All** | **RUNTIME ERROR**  | 0.050 | **0.067** | 0.002 |
| **558B** | **OK** | 0.276 | 0.298 | **0.483** |  
| **558B** | **WRONG ANSWER** | 0.403 | **0.446** | 0.407  |
| **558B** | **RUNTIME ERROR** | 0.350 | **0.373** | 0.342  |
| **922E** | **OK** | 0.320 | 0.304 | **0.419** |  
**922E** | **WRONG ANSWER** | 0.525 | 0.522 | **0.683** |
**922E** | **RUNTIME ERROR** | 0.555 | 0.418 | **0.622** |
| **1142C** | **OK** | 0.331 | 0.541 | **0.694** |  
| **1142C** | **WRONG ANSWER** | 0.561 | 0.555 | **0.620** |
| **1142C** | **RUNTIME ERROR** | 0.382 | 0.371 | **0.426** |  
| **1579A** | **OK** | 0.480 | **0.529** | 0.442  |
| **1579A** | **WRONG ANSWER** | 0.508 | **0.530** | 0.482 |
| **1579A** | **RUNTIME ERROR** | 0.322 | 0.337 | **0.351** |  
| **1553G** | **OK** | 0.284 | 0.307 | **0.640** |  
**1553G** | **WRONG ANSWER** | 0.579 | **0.644** | 0.594 |
| **1553G** | **RUNTIME ERROR**| 0.506 | 0.519 | **0.620** |  

## Discussion

Our experiments help us validate the effectiveness of
our algorithm to measure the similitude between different programs.
Based on the validation we conclude our approach is appropriate to:
(1) Identify features common to different problems, for example,
in the case of the Codeforces corpus, in which
we identify similarities across all analyzed submissions in the way
the input and output of the problem are processed (independent of the
specific instructions used).
(2) Detect differences in the algorithms behind different programs,
even when they are functionally equivalent. (i.e., have the same output for the same inputs).
This is shown in the clusters for the correct
(OK) solutions to a problem in our corpus.

The performance of our algorithm, measured using the silhouette score,
is similar to the performance of the baseline, i.e., the LAV algorithm.
Our evaluation shows that the use of our node similarity definition
has a slight improvement over the baseline in most cases. Moreover,
when analyzing specific algorithm pairs identified as
similar/disimilar, we respectively note a great resemblance/disparity
in the specific implementations. This is beneficial as a notion of
diversity between algorithms. However, the validation shows that in
some cases using node normalization is detrimental to the performance.
We note that, as programs differ but have an important
feature in common (e.g., input/output processing), the
algorithm will detect these as similar, decreasing the silhouette
score.
