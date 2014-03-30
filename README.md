Homework for IF2210 - Object Oriented Programming	{#mainpage}
==================================================

This homework is using C++ for Programming Language. It has classes for representing Date and Time and both of them. It also has class Queue and Teller for representing Banks'Queue. Class Event is a controlling class for user's input. There is a main file that use all of them named main.cpp.

<b>Problem Description :</b><br>
Pada sebuah bank, ada N teller, di depan masing-masing teller ada antrian. Ada N buah teller dinomori T(0) s.d T(N-1). Q(i) adalah antrian di depan teller T(i).<br>

T(i) statusnya 0: menganggur/idle atau 1: sedang melayani<br>

Program utama akan memroses sederetan “event” yang diberikan sebagai input, dan dipastikan eventnya terurut waktu dan membesar (mencerminkan kejadian sesuai dengan berjalannya waktu). Jika ada event yang waktunya bersamaan, anda harus memroses sesuai urutan input. Sebuah event adalah type yang terdiri dari tiga komponen yaitu <T: DateTime; Kode:char; i:integer> yang dijelaskan sebagai berikut : <br>
<ol>
	<li>T adalah type DateTime, dengan Date dan TIme yang harus dibuat sendiri, dengan method yang hanya diperlukan untuk persoalan. Format Input DateTime : DD-MM-YYYY;HH:MM:SS</li>
	<li>Kode adalah sebuah karakter yang bernilai ‘A’ atau ‘D’. A = Arrival (kedatangan pelanggan) dan D = Departure, seorang pelanggan selesai dilayani sehingga harus dihapus dari Queue.</li>
	<li>i adalah nomor ID pelanggan (di-generate secara otomatis oleh program anda terurut mulai dari 1 pada saat Arrival).</li>
</ol>
<p>Program anda akan memproses deretan event yang diberikan sesuai urutan pembacaan secara sekuensial, dan akan berhenti jika T >= Tmax, yang merupakan jam tutup teller. Jika Tmax tercapai, program harus berhenti menangani deretan event, dan akan melakukan penghapusan ke semua pelanggan yang sedang tersisa dengan “merata” artinya ulangi hapus satu per satu dari Q[1], Q[2],..Q[N]. Merata artinya bukan menghabiskan sebuah Queue sampai kosong sekaligus, tapi digilir penghapusannya.</p>

<b>Jockeying</b><br>
<p>Fenomena “jockeying” dalam sebuah antrian adalah terjadinya seorang pelanggan pindah ke antrian lain, karena sesuatu sebab. Yang paling sering adalah karena melihat bahwa Queue di dekatnya lebih pendek. Padahal, belum tentu kalau antrian lebih pendek akan lebih cepat dilayani sebab tergantung kepada lamanya pelayanan pelanggan. Fenomena jockeying dapat menyebabkan pelanggan hanya berpindah-pindah antrian tapi malahan tidak terlayani. Pada Tugas Besar ini, anda akan membuat sebuah algoritma simulasi jockeying ke antrian ke-j ketika terjadi departure di sebuah antrian ke-i karena banyaknya pelanggan yang mengantri di j menjadi lebih kecil dari banyaknya yang mengantri di antrian ke-i.</p>

Spesifikasi “jockeying” adalah sebagai berikut :<br>
int Jockeying(int iOrigin)<br>
/*
iOrigin = nomor Queue asal<br>
Fungsi Jockeying menghasilkan j yaitu nomor Queue tujuan (jika terjadi jockeying),atau -1 (jika tidak terjadi jockeying)<br>
Syarat terjadinya jockeying : Ada queue lain yang lebih pendek dengan selisih lebih dari 2 elemen<br>
Mensimulasikan pelanggan yang berpindah dari Q[iOrigin] ke Q[j] (jika ada)., dengan j != iOrigin dan NbElmt(j) paling minimum. <br>
Jika terdapat lebih dari satu Q[j] dengan NbElmt(j) minimum, pilih j yang paling dekat dengan iOrigin dan j yang memiliki indeks lebih kecil.*/ <br>
