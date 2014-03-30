# - Berikut adalah contoh Makefile untuk autograde
# - Harus ada perintah compile-test untuk kompilasi dan grade untuk eksekusi
# - OUTPUT adalah variabel yang diperlukan, tidak perlu diubah.
# - ADT dan MAIN adalah variabel yang berisi nama-nama file,
#   silahkan diubah sesuai kebutuhan.

OUTPUT=bin
ADT=Time
MAIN=mTime

compile-test: $(MAIN).cpp $(ADT).o
	g++ -o $(MAIN) $(MAIN).cpp $(ADT).o
	
$(ADT).o: $(ADT).cpp $(ADT).h
	g++ -c $(ADT).cpp

grade:
	./$(MAIN)
