# Implement a program that prints out a double half-pyramid of a specified height, per the below.

`$ python mario.py` 
```
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####

```

## TODO

- [x] Ask user for Height
- [x] Print bricks acording to the Height
- [ ] Print left column 
- [ ] Print right column 


### Printing a column 
So far I'm able to print this
```
#
##
###
####
```
#### code: 
`print("#" * i)`

In the example there are spaces at the left, that decrease each row.

So if I add spaces  before printing  the bricks, and decrease the spaces each row, I may get the desired result.

####  solutions's code 
`print(" " * (height - i), end ="")` 
