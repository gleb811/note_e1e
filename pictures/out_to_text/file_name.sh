#!/bin/tcsh -f


foreach f (*.pdf)    

setenv f_new `echo $f | sed -e 's$0.$0_$' -e 's$1.$1_$'`

echo $f_new

mv $f $f_new

end


