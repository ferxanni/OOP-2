# 2 uzduotis

# v1.1
Struktūra data buvo pakeista į Class data, taip pat atsižvelgiant į spartos analizę buvo paimta studentų dalijimo funkcija su List.

Spartos analizė lyginant tuos pačius studentų failus su 10 000 ir 100 000 ir tą pačią studentų dalijimo strategiją su List konteineriu.
| Studentu Skaicius | Struct. Data | Class Data |
|-------------------|--------------|------------|
| 10 000            | 0.182981 s   | 0.221646 s |
| 100 000           | 1.82583 s    | 2.03903 s  |

Spartos analizė naudojant flag'us O1, O2, O3
| Flag | 1 000      | 10 000       | 100 000     | 
|------|------------|--------------|-------------|
| O1   | 0.0461067 s| 0.208383 s   |  1.71877 s  |
| O2   | 0.0319225 s| 0.20121 s    | 2.11753 s   |
| O3   | 0.0344436 s| 0.201824 s   | 2.06175 s   |
