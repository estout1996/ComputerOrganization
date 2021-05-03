/*Elizabeth Stout
  CPSC 2310 Assignment 4
  Due August 1, 2020

  Encode: Encodes and decodes a messages with this formula
      Encoding = message[i] + key[i] iff message[i] && key[i] are lowercase ascii characters
          = Encoding - 26 iff Encoding > 26
    Decoding = message[i] - key[i] iff message[i] && key[i] are lowercase ascii characters
          = Decoding + 26 iff Decoding <= 0
In both cases, the characters are converted back to ascii characters based on the index that is calculated

*/

.text
.align 4
.global encode
.type encode, %function
encode:
    push {r4-r6, lr}

    input      .req r0
    output     .req r1
    key        .req r2
    which      .req r3
    offset     .req r4
    currinput  .req r5
    currkey    .req r6

    // Set offset to 0
    mov offset, #0 

    change:
        ldrb currinput, [input], #1 // Load *input into currinput, then add 1
        cmp currinput, #0
        beq over // If null character, finish the transformation loop

        ldrb currkey, [key, offset] // Get the key character at the current offset
        add offset, offset, #1 // Add to the key offset

        cmp currkey, #0
        bne next // If the key character is the null character reset it back to the beginning of the key
        
        reset:
            mov offset, #1
            ldrb currkey, [key] // Reset to first character
        
        next:
            //move on from anything that is not a lowercase letter
            cmp currinput, #0x61
            blt store

            cmp currinput, #0x7A
            bgt store
            
            cmp currkey, #0x61
            blt store
            
            cmp currkey, #0x7A
            bgt store

            // update index
            sub currinput, currinput, #0x60
            sub currkey, currkey, #0x60

            // decode if value is 1, encode if value is 0
            cmp which , #1 
            beq decode

            encodes:
                // Encode phrase
                add currinput, currinput, currkey
                cmp currinput, #26
                subgt currinput, currinput, #26

                // Convert back to ascii character given index
                add currinput, currinput, #0x60
                b store
            
            decode:
                // Decode phrase
                sub currinput, currinput, currkey
                cmp currinput, #0
                addle currinput, currinput, #26

                // Convert back to ascii character given index
                add currinput, currinput, #0x60

        store:
            // Store character at current position
            strb currinput, [output], #1 

        b change
    
    over:
        // Add null character to output
        strb currinput, [output] 
    
    .unreq input 
    .unreq output
    .unreq key   
    .unreq which 
    .unreq offset
    .unreq currinput
    .unreq currkey

    pop {r4-r6, pc}
