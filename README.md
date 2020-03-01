# NKiralynoFeladat

Az N királynő-problémát arrol szol, hogy hányféleképpen lehet N királynőt egy N×N-es sakktáblán úgy elhelyezni, hogy a 
sakkszabályok szerint ne üssék egymást vagyis, hogy 2 bábu ne legyen azonos sorban, oszlopban vagy átlóban.

Kiértékelés:
1. N=4 értekadasok száma
    Nyers backtracking:12
    Backtracking + MVR + forward checking:22
    Backtracking + MVR + AC-3:18
    
2. N=5 értekadasok száma
    Nyers backtracking:5
    Backtracking + MVR + forward checking:5
    Backtracking + MVR + AC-3:5
    
3. N=15 értekadasok száma
    Nyers backtracking:2.703
    Backtracking + MVR + forward checking:27
    Backtracking + MVR + AC-3:25
    
4. N=25 értekadasok száma
    Nyers backtracking:97.341
    Backtracking + MVR + forward checking:643
    Backtracking + MVR + AC-3:641
    
5. N=30 értekadasok száma
    Nyers backtracking:112.859.208
    Backtracking + MVR + forward checking:30
    Backtracking + MVR + AC-3:30

6. N=35 értekadasok száma
    Nyers backtracking:471.099.113
    Backtracking + MVR + forward checking:49
    Backtracking + MVR + AC-3:47
    
7. N=500 értekadasok száma
    Nyers backtracking:-
    Backtracking + MVR + forward checking:1.790
    Backtracking + MVR + AC-3:1.782
    
8. N=1.000 értekadasok száma
    Nyers backtracking:-
    Backtracking + MVR + forward checking:2.788
    Backtracking + MVR + AC-3:2.784
    
9. N=3.000 értekadasok száma
    Nyers backtracking:471.099.113
    Backtracking + MVR + forward checking:10.110
    Backtracking + MVR + AC-3:10.084
