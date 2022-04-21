# General Analysis of Sorting
### Merge Sorting
* With a list size of 25000, the sort had a run time of 63
### Quick Sorting (Original w/ Bad Pivot)
```
pivot = arr[0];
```
* With a list size of 25000, the sort had a run time of 81

### Quick Sorting (Original w/ Good Pivot)
```
pivot = median of First + Mid + Last;
```
* With a list size of 25000, the sort had a run time of 78

### Quick Sorting (In place w/ Bad Pivot)
```
pivot = list[low];
```
* With a list size of 25000, the sort had a run time of 6
### Quick Sorting (In place w/ Good Pivot)
```
pivot = median of First + Mid + Last;
```
* With a list size of 25000, the sort had a run time of 4

### Conclusions
With a smaller set of data, bad pivot and good pivot quick sorts generally performed similarly.
As data sizes increased to the millions, in-place quick sort became more reliable, with merge sort lagging slightly behind in run time, and basic quick sort taking a lot longer than all other sorts.
