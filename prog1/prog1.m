comment('Elizabeth Stout')
comment('CPSC 2310 Assignment 1')
comment('Due July 8, 2020')
comment('This program takes the binary number stored in N and converts to the decimal representation')

label(words)
  word(N, 1101)
  word(two, 2)
  word(place, 1)      comment('Store the current space (ie. 1s place, 10s place, etc...)')
  word(ten, 10)
  word(temp, 0)       comment('A temporary storage place for modulus operation')
  word(current, 0)    comment('A storage place for the result of the modulus')
  word(decimal, 0)    comment('A storage place for the current decimal representation')
  word(base, 1)       comment('A storage place for the exponent of the given binary place')
  word(one, 1)

label(start)

  label(loop)         comment('loop through binary number')
    load(place)       comment('end the loop if the current place is greater than the number')
    sub(N)
    bgt0(done)

    load(N)           comment('divide the binary number by the current place')
    div(place)
    store(current)

    div(two)          comment('use the result to attempt to get back to the dividend')
    mul(two)
    store(temp)

    load(current)     comment('subtract the dividend by the result of trying to get back to it')
    sub(temp)         comment('mimicks modulus')

    mul(base)         comment('multiply either 1 or 0 by the base')
    add(decimal)      comment('add to the current decimal representation of the number')
    store(decimal)
    load(base)        comment('base * 2')
    mul(two)
    store(base)
    load(place)       comment('move to the next place in the binary number')
    mul(ten)
    store(place)

    ba(loop)          comment('restart loop')




label(done)
  print(decimal)      comment('Print the decimal representation of the number')

  halt
  end(start)