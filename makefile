test.vvp : *.v
	iverilog -o test.vvp *.v
	vvp test.vvp
catche.out:direct_mapped_cache.cpp
	g++ -o catche.out direct_mapped_cache.cpp
clean:
	rm -d DCACHE.txt ICACHE.txt test.vvp
