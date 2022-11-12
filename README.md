# LEETCODE
This repository is used to track leetcode problems and notes.

## Table of Content
### [Problem List](#Problems)
- [Array](#Array)
- [String](#String)
- [Binary Search](#Binary-Search)
- [BackTracking](#BackTracking)
- [Two pointers](#Two-pointers)
- [Linked List](#Linked-List)
- [Hash Table](#Hash-Table)
- [Bit Manipulation](#Bit-Manipulation)
- [DP](#DP)
- [Binary Search](#Binary-Search) 
- [Tree](#Tree)
- [Interval](#Interval)
- [Graph](#Graph)
- [Math](#Math)
- [Stack and Queue](#Stack-and-Queue)
- [Heap](#Heap)
- [Design](#Design)
- [Greedy](#Greedy)
- [Union Find](#Union-Find)
- [Matrix](#Matrix)

### [Classic Topic Sum](#Classic-topics)
- [Parentheses](#Parentheses)
- [Number of Islands](#Number-of-Islands)
- [Top K](#Top-K)
- [Two Sum](#Two-Sum)
- [Palindrome](#Palindrome)
- [Sell Stock](#Sell-Stock)

### [Blind Top 75 Questions](#75-top-questions-from-blind)
---

## Problems
### Array
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|16| [3Sum Closest](https://leetcode.com/problems/3sum-closest/) |Array|Medium|[C++](./Arrays/16_3SumClosest.cpp)|
|27| [Remove Element](https://leetcode.com/problems/remove-element/) |Array|Easy|[C++](./Arrays/27_RemoveElement.cpp)|
|41| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) |Array|Hard|[C++](./Arrays/41_FirstMissingPositive.cpp)||
|42| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) |Array|Hard|[C++](./Arrays/42_TrappingRainWater.cpp)|\*|
|55| [Jump Game II](https://leetcode.com/problems/jump-game/) |Array|Medium|[C++](./Arrays/55_JumpGame.cpp)|\*|
|55| [Jump Game](https://leetcode.com/problems/jump-game/) |Array|Medium|[C++](./Arrays/55_JumpGame.cpp)|\*|
|80| [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) |Array, Two Pointers|Medium|[C++](./Arrays/55_JumpGame.cpp)|\*|
|118| [Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) |Array|Easy|[C++](./Arrays/118_PascalsTriangle.cpp)|
|119| [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) |Array|Easy|[C++](./Arrays/119_PascalsTriangleII.cpp)|
|121| [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) |Array|Easy|[C++](./Arrays/121_BestTimetoBuyandSellStock.cpp)|
|167| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |Array, Two pointers|Medium|[C++](./Arrays/167_TwoSumII-InputArrayIsSorted.cpp)|
|334| [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) |Array|Medium|[C++](./Arrays/167_TwoSumII-InputArrayIsSorted.cpp)|
|353| [Design Snake Game](https://leetcode.com/problems/design-snake-game/) |Array, Deque|Medium|[C++](./Arrays/353_DesignSnakeGame.cpp)|\*|
|645| [Set Mismatch](https://leetcode.com/problems/set-mismatch/) |Array|Easy|[C++](./Arrays/645_SetMismatch.cpp)||
|836| [Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/) |Array|Easy|[C++](./Arrays/836_RectangleOverlap.cpp)||
|1710| [Maximum Units on a Truck](https://leetcode.com/problems/maximum-units-on-a-truck/)|Array, Sort|Easy|[C++](./Arrays/1710_MaximumUnitsonaTruck.cpp)|
|1822| [Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/) |Array|Easy|[C++](./Arrays/1822_SignoftheProductofanArray.cpp)|
|2279| [Maximum Bags With Full Capacity of Rocks](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/) |Array, Sort|Medium|[C++](./Arrays/1822_SignoftheProductofanArray.cpp)|

* ``Prefix Sum``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|1031| [Maximum Sum of Two Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/) |Prefix Sum|Medium|[C++](./Arrays/1822_SignoftheProductofanArray.cpp)|

### String
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|65| [Valid Number](https://leetcode.com/problems/valid-number/)|String|Hard|[C++](./string/65_ValidNumber.cpp)|
|151| [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)|String|Medium|[C++](./string/151_ReverseWordsinaString.cpp)|
|249| [Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/)|String|Medium|[C++](./string/249_GroupShiftedStrings.cpp)|
|344| [Reverse String](https://leetcode.com/problems/reverse-string/)|String|Easy|[C++](./string/344_ReverseString.cpp)|
|433| [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/)|String, BFS|Medium|[C++](./string/433_MinimumGeneticMutation.cpp)|\*|
|696| [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/)|String|Easy|[C++](./string/696_CountBinarySubstrings.cpp)|
|937| [ReReorder Data in Log Files](https://leetcode.com/problems/reorder-data-in-log-files/)|String|Medium|[C++](./string/937_ReorderDatainLogFiles.cpp)|
|1047| [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)|String|Easy|[C++](./string/1047_RemoveAllAdjacentDuplicatesInString.cpp)|
|1268| [Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)|String|Medium|[C++](./string/1268_SearchSuggestionsSystem.cpp)|\*|
|1328| [Break a Palindrome](https://leetcode.com/problems/break-a-palindrome/)|String|Medium|[C++](./string/1328_BreakaPalindrome.cpp)|
|1592| [Rearrange Spaces Between Words](https://leetcode.com/problems/rearrange-spaces-between-words/)|String|Easy|[C++](./string/1592_RearrangeSpacesBetweenWords.cpp)|
|1832| [Check if the Sentence Is Pangram](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)|String|Easy|[C++](./string/1832_CheckiftheSentenceIsPangram.cpp)|
|2000| [Reverse Prefix of Word](https://leetcode.com/problems/reverse-prefix-of-word/)|String|Easy|[C++](./string/2000_ReversePrefixofWord.cpp)|
|2259| [Remove Digit From Number to Maximize Result](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/)|String|Easy|[C++](./string/2000_ReversePrefixofWord.cpp)|

* ``Aggregate Substring``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|828| [Count Unique Characters of All Substrings of a Given String](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/)|String, Aggregate Substring|Hard|[C++](./string/828_CountUniqueCharactersofAllSubstringsofaGivenString.cpp)|\*|
|2063| [Vowels of All Substrings](https://leetcode.com/problems/vowels-of-all-substrings/)|String, Aggregate Substring|Medium|[C++](./string/2063_VowelsofAllSubstrings.cpp)|
|2262| [Total Appeal of A String](https://leetcode.com/problems/total-appeal-of-a-string/)|String, Aggregate Substring|Hard|[C++](./string/2262_TotalAppealofAString.cpp)|\*|

### Binary Search
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|1283| [Find the Smallest Divisor Given a Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)|Binary Search|Medium|[C++](./binarySearch/1283_FindtheSmallestDivisorGivenaThreshold.cpp)|
|1482| [Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)|Binary Search|Medium|[C++](./binarySearch/1482_MinimumNumberofDaystoMakemBouquets.cpp)|

### BackTracking
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|79| [Word Search](https://leetcode.com/problems/word-search/) |BackTracking|Medium|[C++](./backTracking/79_WordSearch.cpp)|\*|

### Two Pointers
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|345| [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/) |Two Pointers|Easy|[C++](./dp/twoPointers/1578_MinimumTimetoMakeRopeColorful.cpp)|
|1578| [Minimum Time to Make Rope Colorful](https://leetcode.com/problems/minimum-time-to-make-rope-colorful/) |Two Pointers|Medium|[C++](./dp/twoPointers/1578_MinimumTimetoMakeRopeColorful.cpp)|

* ``Sliding Window``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|340| [Longest Substring with At Most K Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) |Sliding Window, String|Medium|[C++](./dp/twoPointers/slidingWindow/340_LongestSubstringwithAtMostKDistinctCharacters.cpp)|
|424| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) |Sliding Window, String|Medium|[C++](./dp/twoPointers/slidingWindow/424_LongestRepeatingCharacterReplacement.cpp)|\*|
|1477| [Find Two Non-overlapping Sub-arrays Each With Target Sum](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/) |Sliding Window, Prefix Sum|Medium|[C++](./dp/twoPointers/slidingWindow/1477_FindTwoNonoverlappingSubarraysEachWithTargetSum.cpp)|\*|

### Hash Table
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|128| [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) |Hash Table|Medium|[C++](./hashTable/128_LongestConsecutiveSequence.cpp)|
|146| [LRU Cache](https://leetcode.com/problems/my-calendar-iii/) |Hash Table, Scan line|Medium|[C++](./hashTable/146_LRUCache.cpp)|
|219| [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) |Hash Table|Easy|[C++](./hashTable/219_ContainsDuplicateII.cpp)|\*|
|981| [Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/) |Hash Table|Medium|[C++](./hashTable/981_TimeBasedKeyValueStore.cpp)|
|2347| [Best Poker Hand](https://leetcode.com/problems/best-poker-hand/) |Hash Table|Easy|[C++](./hashTable/981_TimeBasedKeyValueStore.cpp)|
|2357| [Make Array Zero by Subtracting Equal Amounts](https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/) |Hash Table|Easy|[C++](./hashTable/981_TimeBasedKeyValueStore.cpp)|

### Bit Manipulation
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|191| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) |Bit Manipulation|Easy|[C++](./bitManipulation/191_Numberof1Bits.cpp)|
|268| [Missing Number](https://leetcode.com/problems/missing-number/) |Bit Manipulation|Easy|[C++](./bitManipulation/268_MissingNumber.cpp)|
|338| [Counting Bits](https://leetcode.com/problems/counting-bits/) |Bit Manipulation|Easy|[C++](./bitManipulation/338_CountingBits.cpp)|
|371| [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) |Bit Manipulation|Medium|[C++](./bitManipulation/371_SumofTwoIntegers.cpp)|
|1404| [Number of Steps to Reduce a Number in Binary Representation to One](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/) |Bit Manipulation, String|Medium|[C++](./bitManipulation/1404_NumberofStepstoReduceaNumberinBinaryRepresentationtoOne.cpp)|

### Linked List
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|23| [Merge k Sorted List](https://leetcode.com/problems/merge-k-sorted-lists/) |Linked List|Hard|[C++](./linkedList/23_MergekSortedList.cpp)|
|25| [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) |Linked List|Hard|[C++](./linkedList/25_ReverseNodesinkGroup.cpp)|
|141| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) |Linked List, Two Pointers|Easy|[C++](./linkedList/fastSlowPointer/141_LinkedListCycle.cpp)|
|237| [Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list/) |Linked List|Medium|[C++](./linkedList/237_DeleteNodeinaLinkedList.cpp)|
|2095| [Delete the Middle Node of a Linked List](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/) |Linked List|Medium|[C++](./linkedList/2095_DeletetheMiddleNodeofaLinkedList.cpp)|
|287| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) |Linked List, Two Pointers|Easy|[C++](./linkedList/fastSlowPointer/287_FindtheDuplicateNumber.cpp)|

### Tree
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|112| [Path Sum](https://leetcode.com/problems/path-sum/) |Binary Tree, DFS, BFS|Easy|[C++](./Tree/traversal/112_PathSum.cpp)|
|623| [Add One Row to Tree](https://leetcode.com/problems/add-one-row-to-tree/) |Binary Tree, BFS|Medium|[C++](./Tree/traversal/623_AddOneRowtoTree.cpp)|
|863| [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) |Binary Tree, BFS|Medium|[C++](./Tree/traversal/863_AllNodesDistanceKinBinaryTree.cpp)|\*|


* ``Tree Traversal``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|114| [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) |DFS, Pre order|Medium|[C++](./Tree/traversal/114_FlattenBinaryTreetoLinkedList.cpp)|
|117| [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) |DFS|Medium|[C++](./Tree/traversal/117_PopulatingNextRightPointersinEachNodeII.cpp)|
|226| [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) |DFS|Easy|[C++](./Tree/traversal/226_InvertBinaryTree.cpp)|
|559| [Maximum Depth of N-ary Tree](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/) |BFS|Easy|[C++](./Tree/traversal/559_MaximumDepthofNaryTree.cpp)|
|653| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) |Hash Table, BFS|Easy|[C++](./Tree/traversal/653_TwoSumIVInputisaBST.cpp)|
|993| [Cousins in Binary Tree](https://leetcode.com/problems/cousins-in-binary-tree/) |BFS|Easy|[C++](./Tree/traversal/653_TwoSumIVInputisaBST.cpp)|

* ``Binary Search Tree``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|0| [Binary Search Tree Template]() |||[C++](./templates/BinarySearchTree.cpp)||
|173| [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) |DFS, BFS|Easy|[C++](./Tree/bst/173_BinarySearchTreeIterator.cpp)|\*\*|
|653| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) |Hash Table, BFS|Easy|[C++](./Tree/bst/653_TwoSumIVInputisaBST.cpp)|\*\*|

* ``Trie, prefix tree``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|000| [Trie Template]() |Trie||[C++](./templates/Trie.cpp)|\*\*|
|208| [ Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) |Trie|Medium|[C++](./Tree/trie/208_ImplementTriePrefixTree.cpp)|\*|
|211| [Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) |Trie|Medium|[C++](./Tree/trie/211_DesignAddandSearchWordsDataStructure.cpp)|\*|
|212| [Word Search II](https://leetcode.com/problems/word-search-ii/) |Trie|Hard|[C++](./Tree/trie/212_WordSearchII.cpp)|\*|
|421| [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) |Bitwise Trie|Medium|[C++](./Tree/trie/421_MaximumXORofTwoNumbersinanArray.cpp)|\*|


### Interval
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|732| [My Calendar III](https://leetcode.com/problems/my-calendar-iii/) |Interval|Hard|[C++](./interval/732_MyCalendarIII.cpp)|\*|

### DP
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|91| [Decode Ways](https://leetcode.com/problems/decode-ways/) |DP|Medium|[C++](./dp/91_DecodeWays.cpp)|
|309| [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |DP|Medium|[C++](./dp/115_DistinctSubsequences.cpp)|\*|
|322| [Coin Change](https://leetcode.com/problems/coin-change/) |DP|Medium|[C++](./dp/322_CoinChange.cpp)|\*|
|1155| [Number of Dice Rolls With Target Sum](https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/) |DP|Medium|[C++](./dp/1155_NumberofDiceRollsWithTargetSum.cpp)|\*|
|1531| [String Compression II](https://leetcode.com/problems/string-compression-ii/) |DP|Medium|[C++](./dp/1531_StringCompressionII.cpp)|\*|

* ``Game Theory``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|10| [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) |DP Game Theory|Hard|[C++](./dp/gameTheory/10_RegularExpressionMatching.cpp)|
|44| [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/) |DP Game Theory|Hard|[C++](./dp/gameTheory/44_WildcardMatching.cpp)|
|72| [Edit Distance](https://leetcode.com/problems/edit-distance/) |DP Game Theory|Hard|[C++](./dp/gameTheory/72_EditDistance.cpp)|
|115| [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/) |DP Game Theory|Medium|[C++](./dp/gameTheory/115_DistinctSubsequences.cpp)|
|877| [Stone Game](https://leetcode.com/problems/stone-game/) |DP Game Theory|Medium|[C++](./dp/gameTheory/877_StoneGame.cpp)|
|1140| [Stone Game II](https://leetcode.com/problems/stone-game-ii/) |DP Game Theory|Medium|[C++](./dp/gameTheory/1140_StoneGameII.cpp)|


* ``Longest Increasing Subsequence``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|72| [Edit Distance](https://leetcode.com/problems/edit-distance/) |DP Game Theory|Hard|[C++](./dp/gameTheory/72_EditDistance.cpp)|\*|
|161| [One Edit Distance](hhttps://leetcode.com/problems/one-edit-distance/) |Two Pointers|Medium|[C++](./dp/gameTheory/161_OneEditDistance.cpp)||
|300| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) |DP, LIS|Medium|[C++](./dp/LongestIncreasingSubsequence/300_LongestIncreasingSubsequence.cpp)|\*|
|1048| [Longest String Chain](https://leetcode.com/problems/longest-string-chain/) |DP, LIS|Medium|[C++](./dp/LongestIncreasingSubsequence/1048_LongestStringChain.cpp)|\*|


### Graph
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|210| [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) |Graph, BFS|Medium|[C++](./graph/bfs/210_CourseScheduleII.cpp)|\*|
|399| [Evaluate Division](https://leetcode.com/problems/evaluate-division/) |Graph, DFS|Medium|[C++](./graph/dfs/399_EvaluateDivision.cpp)|\*|
|841| [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/) |Graph, DFS|Medium|[C++](./graph/dfs/841_KeysandRooms.cpp)|
|1091| [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) |Graph, BFS|Medium|[C++](./graph/bfs/1091_ShortestPathinBinaryMatrix.cpp)|\*|
|1615| [Maximal Network Rank](https://leetcode.com/problems/maximal-network-rank/) |Graph|Medium|[C++](./graph/bfs/1091_ShortestPathinBinaryMatrix.cpp)|\*|


### Math
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|12| [Integer to Roman](https://leetcode.com/problems/integer-to-roman/) |Math|Medium|[C++](./math/12_IntegertoRoman.cpp)|
|67| [Add Binary](https://leetcode.com/problems/add-binary/) |Math|Easy|[C++](./math/67_AddBinary.cpp)|
|168| [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) |Math|Easy|[C++](./math/168_ExcelSheetColumnTitle.cpp)|
|171| [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) |Math|Easy|[C++](./math/171_ExcelSheetColumnNumber.cpp)|
|204| [Count Primes](https://leetcode.com/problems/count-primes/) |Math|Medium|[C++](./math/204_CountPrimes.cpp)|
|523| [Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) |Math|Medium|[C++](./math/523_ContinuousSubarraySum.cpp)|
|976| [Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle/) |Math|Easy|[C++](./math/204_CountPrimes.cpp)|
|1304| [Find N Unique Integers Sum up to Zero](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/) |Math|Easy|[C++](./math/1304_FindNUniqueIntegersSumuptoZero.cpp)|

### Stack and Queue
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|895| [Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack/) |Stack|Hard|[C++](./stack_queue/895_MaximumFrequencyStack.cpp)||
|1381| [Design a Stack With Increment Operation](https://leetcode.com/problems/design-a-stack-with-increment-operation/) |Stack|Medium|[C++](./stack_queue/1381_DesignaStackWithIncrementOperation.cpp)||

* ``Priority Queue``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|692| [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/) |Priority Queue|Medium|[C++](./stack_queue/priorityQueue/692_TopKFrequentWords.cpp)|\*|

* ``Monotinic Stack``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|84| [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) |Monotinic Stack|Hard|[C++](./stack_queue/monotonic_stack/84_LargestRectangleinHistogram.cpp)|\*|
|85| [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/) |Monotinic Stack|Hard|[C++](./stack_queue/monotonic_stack/85_MaximalRectangle.cpp)||
|901| [Online Stock Span](https://leetcode.com/problems/online-stock-span/) |Monotinic Stack|Medium|[C++](./stack_queue/901_OnlineStockSpan.cpp)||
|907| [Sum of Subarray Minimums](https://leetcode.com/problems/sum-of-subarray-minimums/) |Monotinic Stack|Medium|[C++](./stack_queue/monotonic_stack/85_MaximalRectangle.cpp)||
|2104| [Sum of Subarray Ranges](https://leetcode.com/problems/sum-of-subarray-ranges/) |Monotinic Stack|Hard|[C++](./stack_queue/monotonic_stack/2104_SumofSubarrayRanges.cpp)|\*\*|
|2334| [Subarray With Elements Greater Than Varying Threshold](https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/) |Monotinic Stack|Hard|[C++](./stack_queue/monotonic_stack/2334_SubarrayWithElementsGreaterThanVaryingThreshold.cpp)||

### Heap
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|347| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) |Heap|Medium|[C++](./heap/347_TopKFrequentElements.cpp)|\*|
|658| [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/) |Heap|Medium|[C++](./heap/658_FindKClosestElements.cpp)|\*|
|1642| [Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/) |Heap|Medium|[C++](./heap/1642_FurthestBuildingYouCanReach.cpp)|\*|

### Design
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|1603| [Design Parking System](https://leetcode.com/problems/design-parking-system/) |Design, Counting|Easy|[C++](./design/1603_DesignParkingSystem.cpp)||

### Greedy
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|135| [Candy](https://leetcode.com/problems/design-parking-system/) |Greedy|Hard|[C++](./greedy/135_Candy.cpp)||
|2136| [Earliest Possible Day of Full Bloom](https://leetcode.com/problems/earliest-possible-day-of-full-bloom/) |Greedy|Hard|[C++](./greedy/2136_EarliestPossibleDayofFullBloom)||

### Union Find
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|000| [Union Find Template]() |Union Find||[C++](./templates/UnionFind.cpp)|\*\*|
|128| [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) |Union Find|Medium|[C++](./hashTable/128_LongestConsecutiveSequence.cpp)|\*\*|
|305| [Number of Islands II](https://leetcode.com/problems/number-of-islands-ii/) |Union Find|Hard|[C++](./unionFind/305_NumberofIslandsII.cpp)|\*|

### Matrix
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|48| [Rotate Image](https://leetcode.com/problems/rotate-image/) |Matrix|Medium|[C++](./matrix/48_RotateImage.cpp)|
|73| [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) |Matrix|Medium|[C++](./matrix/73_SetMatrixZeroes.cpp)|
|348| [Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/) |Matrix|Medium|[C++](./matrix/348_DesignTicTacToe.cpp)|\*|
|766| [Toeplitz Matrix](https://leetcode.com/problems/toeplitz-matrix/) |Matrix|Easy|[C++](./matrix/766_ToeplitzMatrix.cpp)|
|835| [Image Overlap](https://leetcode.com/problems/image-overlap/) |Matrix|Medium|[C++](./matrix/835_ImageOverlap.cpp)|
|1293| [Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) |BFS|Hard|[C++](./matrix/1293_ShortestPathinaGridwithObstaclesElimination.cpp)|\*|
|1706| [Where Will the Ball Fall](https://leetcode.com/problems/where-will-the-ball-fall/) |Matrix|Medium|[C++](./matrix/1706_WhereWilltheBallFall.cpp)||


# Classic topics
### Parentheses
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|20| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) |Stack|Easy|[C++](./classicTopics/parentheses/20_ValidParentheses.cpp)|\*|
|32| [Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) |Stack, Two Pass|Hard|[C++](./classicTopics/parentheses/32_LongestValidParentheses.cpp)|\*|
|856| [Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/) |Stack|Medium|[C++](./classicTopics/parentheses/856_ScoreofParentheses.cpp)|\*|
|1249| [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) |Stack|Medium|[C++](./classicTopics/parentheses/1249_MinimumRemovetoMakeValidParentheses.cpp)|\*|
|921| [Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) |Rolling state|Medium|[C++](./classicTopics/parentheses/921_MinimumAddtoMakeParenthesesValid.cpp)|\*|
|1614| [Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) |Rolling state|Medium|[C++](./classicTopics/parentheses/1614_MaximumNestingDepthoftheParentheses.cpp)||

### Number of Islands
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|200| [Number of Islands](https://leetcode.com/problems/number-of-islands/) |DFS, BFS|Medium|[C++](./classicTopics/numberOfIslands/200_NumberofIslands.cpp)|\*|
|305| [Number of Islands II](https://leetcode.com/problems/number-of-islands-ii/) |Union Find|Medium|[C++](./unionFind/305_NumberofIslandsII.cpp)|\*|
|463| [Island Perimeter](https://leetcode.com/problems/island-perimeter/) |DFS, BFS|Easy|[C++](./classicTopics/numberOfIslands/463_IslandPerimeter.cpp)||
|547| [Number of Provinces](https://leetcode.com/problems/number-of-provinces/) |Union Find|Medium|[C++](./unionFind/547_NumbeofProvinces.cpp)|\*|
|694| [Number of Distinct Islands](https://leetcode.com/problems/number-of-distinct-islands/) |DFS, BFS|Medium|[C++](./classicTopics/numberOfIslands/694_NumberofDistinctIslands.cpp)|\*|
|695| [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) |DFS, BFS|Medium|[C++](./classicTopics/numberOfIslands/695_MaxAreaofIsland.cpp)||
|827| [Making A Large Island](https://leetcode.com/problems/making-a-large-island/) |Union Find|Hard|[C++](./classicTopics/numberOfIslands/827_MakingALargeIsland.cpp)|\*|
|934| [Shortest Bridge](https://leetcode.com/problems/shortest-bridge/) |DFS, BFS|Medium|[C++](./classicTopics/numberOfIslands/934_ShortestBridge.cpp)|\*|
|1020| [Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/) |DFS, BFS|Medium|[C++](./classicTopics/numberOfIslands/1020_NumberofEnclaves.cpp)|\*|
|1254| [Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/) |DFS|Medium|[C++](./classicTopics/numberOfIslands/1254_NumberofClosedIslands.cpp)|\*|

### Top K
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|347| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) |Heap, Bucket Sort|Medium|[C++](./heap/347_TopKFrequentElements.cpp)|\*|
|451| [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/) |Bucket Sort|Medium|[C++](./classicTopics/topK/347_TopKFrequentElements.cpp)|\*|
|703| [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/) |Priority Queue|Easy|[C++](./classicTopics/topK/347_TopKFrequentElements.cpp)||
|1032| [Stream of Characters](https://leetcode.com/problems/stream-of-characters/) |Last K, Inverse Trie|Hard|[C++](./classicTopics/topK/1032_StreamofCharacters.cpp)|\*|

### Two Sum
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|1| [Two Sum](https://leetcode.com/problems/two-sum/) |Array|Easy|[C++](./Arrays/1_TwoSum.cpp)|
|15| [3Sum](https://leetcode.com/problems/3sum/) |Array, Two Pointers|Medium|[C++](./Arrays/15_3Sum.cpp)|
|16| [3Sum Closest](https://leetcode.com/problems/3sum-closest/) |Array|Medium|[C++](./Arrays/16_3SumClosest.cpp)|
|167| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |Array, Two pointers|Medium|[C++](./Arrays/167_TwoSumII-InputArrayIsSorted.cpp)|
|170| [Two Sum III - Data structure design](https://leetcode.com/problems/two-sum-iii-data-structure-design/) |Hash Table|Easy|[C++](./classicTopics/twoSum/170_TwoSumIIIDatastructuredesign.cpp)|
|259| [3Sum Smaller](https://leetcode.com/problems/3sum-smaller/) |Array|Medium|[C++](./Arrays/259_3SumSmaller.cpp)|
|653| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) |Hash Table, BFS, Stack|Easy|[C++](./Tree/bst/653_TwoSumIVInputisaBST.cpp)|\*\*|

### Palindrome
* ``DP``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|5| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)|String, Center to ends, DP|Medium|[C++](./string/5_LongestPalindromicSubstring.cpp)|\*|
|516| [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) |DP|Medium|[C++](./classicTopics/palindrome/516_LongestPalindromicSubsequence.cpp)|
|647| [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)|String, Center to ends, DP|Medium|[C++](./string/647_PalindromicSubstrings.cpp)||
|1143| [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)|DP|Medium|[C++](./classicTopics/palindrome/1143_LongestCommonSubsequence.cpp)|\*|
|1216| [Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/)|DP|Hard|[C++](./classicTopics/palindrome/1216_ValidPalindromeIII.cpp)|\*|

* ``Easy, Basic``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|9| [Palindrome Number](https://leetcode.com/problems/palindrome-number/) |Math|Easy|[C++](./classicTopics/palindrome/9_PalindromeNumber.cpp)|
|680| [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/) |Two Pointers|Easy|[C++](./classicTopics/palindrome/680_ValidPalindromeII.cpp)|
|234| [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/) |Linked List|Easy|[C++](./linkedList/fastSlowPointer/234_PalindromeLinkedList.cpp)|

* ``BackTracking``

|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|131| [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) |BackTracking|Medium|[C++](./classicTopics/palindrome/131_PalindromePartitioning.cpp)|\*|

### Sell Stock
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|121| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |Array, DP|Easy|[C++](./Arrays/121_BestTimetoBuyandSellStock.cpp)|
|122| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)|DP|Medium|[C++](./classicTopics/sellStock/122_BestTimetoBuyandSellStockII.cpp)|\*|
|123| [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)|DP|Hard|[C++](./classicTopics/sellStock/123_BestTimetoBuyandSellStockIII.cpp)|\*|
|188| [ Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)|DP|Hard|[C++](./classicTopics/sellStock/188_BestTimetoBuyandSellStockIV.cpp)|\*|
|309| [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |DP|Medium|[C++](./dp/115_DistinctSubsequences.cpp)|\*|
|714| [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)|DP|Medium|[C++](./classicTopics/sellStock/714_BestTimetoBuyandSellStockwithTransactionFee.cpp)||

# 75 Top Questions From Blind
### Array
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|1| [Two Sum](https://leetcode.com/problems/two-sum/) |Array|Easy|[C++](./Arrays/1_TwoSum.cpp)|
|11| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/) |Array, Two Pointers|Medium|[C++](./Arrays/11_ContainerWithMostWater.cpp)|
|15| [3Sum](https://leetcode.com/problems/3sum/) |Array, Two Pointers|Medium|[C++](./Arrays/15_3Sum.cpp)|
|33| [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) |Array, Binary Search |Medium|[C++](./Arrays/33_SearchinRotatedSortedArray.cpp)|
|53| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) |Arrays|Medium|[C++](./Arrays/53_MaximumSubarray.cpp)|
|121| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |Array|Easy|[C++](./Arrays/121_BestTimetoBuyandSellStock.cpp)|
|152| [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) |Array, DP|Medium|[C++](./Arrays/152_MaximumProductSubarray.cpp)|
|153| [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) |Arrays|Medium|[C++](./Arrays/153_FindMinimuminRotatedSortedArray.cpp)|
|217| [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/) |Array|Easy|[C++](./Arrays/217_ContainsDuplicate.cpp)|
|238| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) |Array|Medium|[C++](./Arrays/238_ProductofArrayExceptSelf.cpp)|

### Matrix
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|48| [Rotate Image](https://leetcode.com/problems/rotate-image/) |Matrix|Medium|[C++](./matrix/48_RotateImage.cpp)|
|54| [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) |Matrix|Medium|[C++](./matrix/54_SpiralMatrix)|\*|
|73| [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) |Matrix|Medium|[C++](./matrix/73_SetMatrixZeroes.cpp)|
|348| [Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/) |Matrix|Medium|[C++](./matrix/348_DesignTicTacToe.cpp)|\*|
|1275| [Find Winner on a Tic Tac Toe Game](https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/) |Matrix|Medium|[C++](./matrix/1275_FindWinneronaTicTacToeGame.cpp)|

### Bit Manipulation
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|190| [Reverse Bits](https://leetcode.com/problems/reverse-bits/) |Bit Manipulation|Easy|[C++](./bitManipulation/190_ReverseBits.cpp)|
|191| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) |Bit Manipulation|Easy|[C++](./bitManipulation/191_Numberof1Bits.cpp)|
|268| [Missing Number](https://leetcode.com/problems/missing-number/) |Bit Manipulation|Easy|[C++](./bitManipulation/268_MissingNumber.cpp)|
|338| [Counting Bits](https://leetcode.com/problems/counting-bits/) |Bit Manipulation|Easy|[C++](./bitManipulation/338_CountingBits.cpp)|
|371| [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) |Bit Manipulation|Medium|[C++](./bitManipulation/371_SumofTwoIntegers.cpp)|

### Interval
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|56| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) |Interval|Medium|[C++](./interval/56_MergeIntervals.cpp)|
|57| [Insert Interval](https://leetcode.com/problems/insert-interval/) |Interval|Medium|[C++](./interval/57_InsertInterval.cpp)|
|253| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/) |Interval|Medium|[C++](./interval/253_MeetingRoomsII.cpp)|
|435| [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) |Interval|Medium|[C++](./interval/435_Non-overlappingIntervals.cpp)|

### Linked List
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|141| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) |Linked List, Two Pointers|Easy|[C++](./linkedList/fastSlowPointer/141_LinkedListCycle.cpp)|

### String
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|5| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)|String, Center to ends, DP|Medium|[C++](./string/5_LongestPalindromicSubstring.cpp)|\*|
|20| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) |Stack|Easy|[C++](./classicTopics/parentheses/20_ValidParentheses.cpp)|\*|
|49| [Group Anagrams](https://leetcode.com/problems/group-anagrams/)|String|Medium|[C++](./string/49_GroupAnagrams.cpp)||
|76| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) |String, Sliding Window|Hard|[C++](./string/76_MinimumWindowSubstring.cpp)|
|125| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) |String|Easy|[C++](./string/242_ValidAnagram.cpp)|
|242| [Valid Anagram](https://leetcode.com/problems/valid-anagram/) |Hash map|Easy|[C++](./string/242_ValidAnagram.cpp)|
|271| [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/)|String|Medium|[C++](./string/271_EncodeandDecodeStrings.cpp)||
|647| [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)|String, Center to ends, DP|Medium|[C++](./string/647_PalindromicSubstrings.cpp)||


### Tree
|num|Question| Category | Difficulty | Solution |Like|
|---| ------ | -------- | ---------- | -------- | -- |
|102| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) |BFS, DFS|Medium|[C++](./Tree/traversal/104_MaximumDepthofBinaryTree.cpp)|
|104| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) |DFS|Easy|[C++](./Tree/traversal/102_BinaryTreeLevelOrderTraversal.cpp)|
|124| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) |DFS|Hard|[C++](./Tree/traversal/124_BinaryTreeMaximumPathSum.cpp)|\*|
|226| [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/) |DFS|Easy|[C++](./Tree/traversal/226_InvertBinaryTree.cpp)|
|572| [ Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/) |DFS|Easy|[C++](./Tree/traversal/572_SubtreeofAnotherTree.cpp)|\*|
|653| [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) |Hash Table, BFS|Easy|[C++](./Tree/traversal/653_TwoSumIVInputisaBST.cpp)|


