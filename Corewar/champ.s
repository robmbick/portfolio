.name	"SUPER !"
.comment "With love !  :)"

ld %50, r2
sti r1, %:live1, %6
live1:
	live %0
	live %0
	live %0

sti r1, %:live1, %1
sti r1, %:live1, %6
sti r1, %:live1, %11
sti r1, %:rec, %1
sti r1, %:asd, %1
add	r2, r10, r10
asd:
	live %42
fork %:live1
sti r1, %:sss1, %1
ldi %:rec, %1, r1
ld %0, r15
fork %:rec
ld %0, r15
zjmp %:live1
st r6, 880
rec:
	live %42
	fork %:live1
	ld %0, r15
sti r1, %:sss, %1
sti r1, %:live1, %11
sss:
	live %42
ldi	%:live1, %1, r1
sti r1, %:as, %1
sss1:
	live %0
sti r1, %40, r10
as: 
	live %0
ld %0, r15
lfork %1450
ld %0, r15
zjmp %:live1
