#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Bigint {
  string a;
  int sign;
  Bigint(){}
  Bigint( string b ) { (*this) = b; }
  int size () {return a.size(); }
  Bigint inverseSign () { sign *= -1; return (*this); }
  Bigint normalize (int newSign) {
    sign = newSign;
    for (int i = a.size() - 1; i > 0 && a[i] == '0'; i--) a.erase(a.begin() + i);
    if (a.size() == 1 && a[0] == 0) sign = 1;
    return (*this);
  }
  void operator = ( string b ) {
    a = b[0] == '-' ? b.substr(1) : b;
    reverse( a.begin(), a.end() );
    this->normalize( b[0] == '-' ? -1 : 1);
  }
  bool operator < ( const Bigint &b) const {
    if ( a.size() != b.a.size() ) return a.size() < b.a.size();
    for (int i = a.size() - 1; i >= 0; i--) if ( a[i] != b.a[i] ) return a[i] < b.a[i];
    return false;
  }
  Bigint operator + ( Bigint b ) {
    if (sign != b.sign) return (*this) - b.inverseSign();
    Bigint c;
    for (int i = 0, carry = 0; i < (int)a.size() || i < (int)b.size() || carry ; i++) {
      carry += (i < (int)a.size() ? a[i] - 48 : 0) + (i < (int)b.a.size() ? b.a[i] - 48 : 0);
      c.a += (carry % 10 + 48);
      carry /= 10;
    }
    return c.normalize(sign);
  }
  Bigint operator - ( Bigint b ) {
    if ( sign != b.sign ) return (*this) + b.inverseSign();
    if ( (*this) < b ) return (b - (*this)).inverseSign();
    Bigint c;
    for(int i = 0, borrow = 0; i < (int)a.size(); i++) {
      borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
      c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
      borrow = borrow >= 0 ? 0 : 1;
    }
    return c.normalize(sign);
  }
  void print() {
    if (sign == -1) putchar_unlocked( '-' );
    for ( int i = a.size() - 1; i >= 0; i-- ) putchar_unlocked(a[i]);
  }
};

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Bigint a, b, c;
  string s1, s2;
  while (cin >> s1) {
    cin >> s2;
    Bigint z1 = s1, z2 = s2;
    Bigint c = z1 + z2;
    c.print(); putchar_unlocked('\n');
  }
}

/* ********************************

struct Bigint 

  string a : attribute
  int sign : attribute

  Bigint() : constructor

  Bigint( string b ) : constructor
    (*this) = b

  int size () 
    return a.size()
  
  Bigint inverseSign ()
    sign *= -1
    return (*this)
  
  Bigint normalize (int newSign) 
    sign = newSign
    for (int i = a.size() - 1; i > 0 && a[i] == '0'; i--) 
      a.erase(a.begin() + i)
    if (a.size() == 1 && a[0] == 0) 
      sign = 1
    return (*this)
  
  void operator = ( string b )
    if a = b[0] == '-' 
      b.substr(1)
    else
      b
    reverse( a.begin(), a.end() )
    this->normalize( b[0] == '-' ? -1 : 1)
  
  bool operator < ( const Bigint b) const 
    if ( a.size() != b.a.size() ) 
      return a.size() < b.a.size()
    for (int i = a.size() - 1; i >= 0; i--) 
      if ( a[i] != b.a[i] ) 
        return a[i] < b.a[i]
    return false
  
  Bigint operator + ( Bigint b ) 
    if (sign != b.sign) 
      return (*this) - b.inverseSign();
    Bigint c
    for (int i = 0, carry = 0; i < (int)a.size() || i < (int)b.size() || carry ; i++) 
      carry = carry + (i < (int)a.size() ? a[i] - 48 : 0) + (i < (int)b.a.size() ? b.a[i] - 48 : 0)
      c.a = c.a + (carry % 10 + 48)
      carry = carry / 10
    
    return c.normalize(sign);
  
  Bigint operator - ( Bigint b ) 
    if ( sign != b.sign )
      return (*this) + b.inverseSign()
    if ( (*this) < b ) 
      return (b - (*this)).inverseSign()
    Bigint c;
    for (int i = 0, borrow = 0; i < (int)a.size(); i++) 
      borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48)
      c.a = c.a + borrow >= 0 ? borrow + 48 : borrow + 58
      borrow = borrow >= 0 ? 0 : 1
    
    return c.normalize(sign);
  
  void print() 
    if (sign == -1) 
      putchar_unlocked( '-' );
    for ( int i = a.size() - 1; i >= 0; i-- ) 
      putchar_unlocked(a[i]);
  

/*
Bigint adalah typedata yang dapat menampung value
lebih dari long long

main()
  Bigint a, b, c
  string s1, s2
  while input s1 
    input s2;
    Bigint z1 = s1
    Bigint z2 = s2
    Bigint c = z1 + z2;
    output c
*/
/*


teks:
atoqunxykhxsntonntafcjxeyupafqujhuofhdsfnyawuntucjxeyupyabuntuslaqujfuolkuqujhntalihufanfqujhuofhesnhxsgayytoqufxpunjxseyunxiunozzucnukabhxskxlnzojugantntucjxeyupkufzjacnaxloqujhuofhcjxeyupaflxnoygohfoqujhexjalicjxeyupfxpunapufangayyeualnujufnalibjxpntunapuhxsnjhannxntunapuhxsfxyquaneuzosfuobnujyxnfxbgonyuhxsgayybuuyqujhguyyntufslafftalalixsnfakuntugalkxgntueajkfojufalialialntunjuuntulonsjuaftojpxlaxsfgtonfntubajfncjxeyupxbolxlyaludskiuanfocysfecjxeyupalzxppxluvzucnfctujuxlyaludskiuntafcjxeyupgayyeuntubajfncjxeyupxbpxfnxbntuxlyaludskiufntukonoyapanonaxlfojupsynacyunufnzofufoyyntulspeujfojufucojonukehfxpugtanufcozufoolkeojualnuiujfolkyuffntolpovyxlialnalzxjzcysfcysfyolisoiuntualcsnbayugayyyuffntolbxsjpuioehnufatxcuhxszolfxyquanofbofnofcxffaeyueuzosfuanfqujhqujhuofholkntunufnzofufojuqujhguowesnabhxsixngonyuhxsgayygxjwbxjoyxlinapunxbalkntupafnowuxbhxsjcjxijopcxffaeyhuldxhntafcjxeyup

Pada soal ini diberikan deskripsi bahwa seorang bernama Blue Mary mempunyai sebuah set problem yang ditulis dengan bahasa inggris. Karena merasa terlalu mudah untuk menyelesaikan problem tersebut, Blue Mary melakukan enkripsi pada penjelasan problem tersebut. Enkripsi yang dilakukan Blue Mary adalah menghapus semua spasi putih dan tanda baca dalam deskripsi yang asli lalu semua huruf dijadikan lowercase. Kemudian, dia secara acak memilih permutasi dari alfabet huruf kecil bahasa Inggris, dan kemudian menggunakan huruf yang sesuai sebagai pengganti huruf dalam teks aslinya. Pada pendataan terhadap bahasa inggris, alfabet yang paling sering muncul adalah huruf e. Karena enkripsi pada text ini seperti memetakan satu huruf ke huruf yang lain, maka setiap huruf yang sama pada teks yang dienkripsi adalah huruf yang sama apabila didekripsi. Lalu dicari huruf yang paling sering muncul pada kebanyakan kalimat bahasa inggris, yaitu the. Sedangkan pada teks tersebut ditemukan 3 huruf yang paling sering muncul adalah ntu.

Maka didapat hasil setelah mengubah ntu menjadi the:
ahoqetxykhxsthotthafcjxeyepafqejheofhdsftyawethecjxeyepyabetheslaqejfeolkeqejhthalihefatfqejheofhesthxsgayyhoqefxpetjxseyetxietozzectekabhxskxltzojegaththecjxeyepkefzjactaxloqejheofhcjxeyepaflxtoygohfoqejhexjalicjxeyepfxpetapefatgayyeealtejeftalibjxpthetapehxstjhattxthetapehxsfxyqeateezosfeobtejyxtfxbgotyehxsgayybeeyqejhgeyythefslaffhalalixstfakethegalkxgtheeajkfojefalialialthetjeethelotsjeafhojpxlaxsfghotfthebajftcjxeyepxbolxlyaledskieatfocysfecjxeyepalzxppxlevzectfchejexlyaledskiethafcjxeyepgayyeethebajftcjxeyepxbpxftxbthexlyaledskiefthekotoyapatotaxlfojepsytacyeteftzofefoyythelspeejfojefecojotekehfxpeghatefcozefoolkeojealteiejfolkyefftholpovyxlialtalzxjzcysfcysfyolisoiethealcstbayegayyyefftholbxsjpeioehtefahxcehxszolfxyqeatofboftofcxffaeyeeezosfeatfqejhqejheofholktheteftzofefojeqejhgeowestabhxsixtgotyehxsgayygxjwbxjoyxlitapetxbalkthepaftowexbhxsjcjxijopcxffaeyheldxhthafcjxeyep

karena masih belum didapatkan kalimat yang jelas maka dicari beberapa huruf yang sering muncul selanjutnya. Pada sebuah set problem biasaya terdiri dari kata problem, lalu ditemukan cjxeyup adalah kata yang sering muncul selanjutnya. Berikut adalah hasil bila didecrypt dari huruf yang telah ditemukan tadi, yaitu ntu menjadi the dan cjxeyup menjadi problem.

ahoqetolkhosthotthafproblemafqerheofhdsftlawetheproblemlabetheslaqerfeolkeqerhthalihefatfqerheofhbsthosgallhoqefometrosbletoietozzeptekabhoskoltzoregaththeproblemkefzraptaoloqerheofhproblemaflotolgohfoqerhboraliproblemfometamefatgallbealtereftalibromthetamehostrhattothetamehosfolqeatbezosfeobterlotfobgotlehosgallbeelqerhgellthefslaffhalaliostfakethegalkogthebarkforefalialialthetreethelotsreafhormolaosfghotfthebarftproblemobolollaledskieatfoplsfbproblemalzommolevzeptfphereollaledskiethafproblemgallbethebarftproblemobmoftobtheollaledskiefthekotolamatotaolforemsltapleteftzofefollthelsmberforefeporotekbhfomeghatefpozefoolkborealteierfolklefftholmovlolialtalzorzplsfplsflolisoiethealpstbalegalllefftholbosrmeiobhtefahopehoszolfolqeatofboftofpoffablebezosfeatfqerhqerheofholktheteftzofeforeqerhgeowbstabhosiotgotlehosgallgorwborololitametobalkthemaftoweobhosrproirompoffablheldohthafproblem

Setelah dilakukan observasi, terdapat kata thafproblem. Diduga kata yang tepat adalah thisproblem. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihoqetolkhosthotthisproblemisqerheoshdsstliwetheproblemlibethesliqerseolkeqerhthilihesitsqerheoshbsthosgillhoqesometrosbletoietozzeptekibhoskoltzoregiththeproblemkeszriptioloqerheoshproblemislotolgohsoqerhboriliproblemsometimesitgillbeilterestilibromthetimehostrhittothetimehossolqeitbezosseobterlotsobgotlehosgillbeelqerhgellthesslisshililiostsikethegilkogthebirksoresiliiliilthetreethelotsreishormoliossghotsthebirstproblemobololliledskieitsoplssbproblemilzommolevzeptsphereolliledskiethisproblemgillbethebirstproblemobmostobtheolliledskiesthekotolimitotiolsoremsltipletestzosesollthelsmbersoreseporotekbhsomeghitespozesoolkboreilteiersolklesstholmovloliiltilzorzplssplsslolisoietheilpstbilegilllesstholbosrmeiobhtesihopehoszolsolqeitosbostospossiblebezosseitsqerhqerheosholkthetestzosesoreqerhgeowbstibhosiotgotlehosgillgorwborololitimetobilkthemistoweobhosrproirompossiblheldohthisproblem

Setelah dilakukan observasi, terdapat kata thotthisproblem. Diduga kata yang tepat adalah thatthisproblem. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihaqetolkhosthatthisproblemisqerheashdsstliwetheproblemlibethesliqersealkeqerhthilihesitsqerheashbsthosgillhaqesometrosbletoietazzeptekibhoskoltzaregiththeproblemkeszriptiolaqerheashproblemislotalgahsaqerhboriliproblemsometimesitgillbeilterestilibromthetimehostrhittothetimehossolqeitbezasseabterlotsobgatlehosgillbeelqerhgellthesslisshililiostsikethegilkogthebirksaresiliiliilthetreethelatsreisharmoliossghatsthebirstproblemobalolliledskieitsaplssbproblemilzommolevzeptsphereolliledskiethisproblemgillbethebirstproblemobmostobtheolliledskiesthekatalimitatiolsaremsltipletestzasesallthelsmbersareseparatekbhsomeghitespazesaalkbareilteiersalklessthalmavloliiltilzorzplssplsslalisaietheilpstbilegilllessthalbosrmeiabhtesihopehoszalsolqeitasbastaspossiblebezasseitsqerhqerheashalkthetestzasesareqerhgeawbstibhosiotgatlehosgillgorwboralolitimetobilkthemistaweobhosrproirampossiblheldohthisproblem

Setelah dilakukan observasi, terdapat kata ihaqe. Diduga kata yang tepat adalah ihave. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihavetolkhosthatthisproblemisverheashdsstliwetheproblemlibethesliversealkeverhthilihesitsverheashbsthosgillhavesometrosbletoietazzeptekibhoskoltzaregiththeproblemkeszriptiolaverheashproblemislotalgahsaverhboriliproblemsometimesitgillbeilterestilibromthetimehostrhittothetimehossolveitbezasseabterlotsobgatlehosgillbeelverhgellthesslisshililiostsikethegilkogthebirksaresiliiliilthetreethelatsreisharmoliossghatsthebirstproblemobalolliledskieitsaplssbproblemilzommolevzeptsphereolliledskiethisproblemgillbethebirstproblemobmostobtheolliledskiesthekatalimitatiolsaremsltipletestzasesallthelsmbersareseparatekbhsomeghitespazesaalkbareilteiersalklessthalmavloliiltilzorzplssplsslalisaietheilpstbilegilllessthalbosrmeiabhtesihopehoszalsolveitasbastaspossiblebezasseitsverhverheashalkthetestzasesareverhgeawbstibhosiotgatlehosgillgorwboralolitimetobilkthemistaweobhosrproirampossiblheldohthisproblem

Setelah dilakukan observasi, terdapat kata thatthisproblemisverheash. Diduga kata yang tepat adalah thatthisproblemisveryeasy. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihavetolkyosthatthisproblemisveryeasydsstliwetheproblemlibethesliversealkeverythiliyesitsveryeasybstyosgillhavesometrosbletoietazzeptekibyoskoltzaregiththeproblemkeszriptiolaveryeasyproblemislotalgaysaveryboriliproblemsometimesitgillbeilterestilibromthetimeyostryittothetimeyossolveitbezasseabterlotsobgatleyosgillbeelverygellthesslisshililiostsikethegilkogthebirksaresiliiliilthetreethelatsreisharmoliossghatsthebirstproblemobalolliledskieitsaplssbproblemilzommolevzeptsphereolliledskiethisproblemgillbethebirstproblemobmostobtheolliledskiesthekatalimitatiolsaremsltipletestzasesallthelsmbersareseparatekbysomeghitespazesaalkbareilteiersalklessthalmavloliiltilzorzplssplsslalisaietheilpstbilegilllessthalbosrmeiabytesihopeyoszalsolveitasbastaspossiblebezasseitsveryveryeasyalkthetestzasesareverygeawbstibyosiotgatleyosgillgorwboralolitimetobilkthemistaweobyosrproirampossiblyeldoythisproblem

Setelah dilakukan observasi, terdapat kata ihavetolkyos. Diduga kata yang tepat adalah ihavetoldyou. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihavetoldyouthatthisproblemisveryeasydustliwetheproblemlibetheuliversealdeverythiliyesitsveryeasybutyougillhavesometroubletoietazzeptedibyoudoltzaregiththeproblemdeszriptiolaveryeasyproblemislotalgaysaveryboriliproblemsometimesitgillbeilterestilibromthetimeyoutryittothetimeyousolveitbezauseabterlotsobgatleyougillbeelverygellthesulisshililioutsidethegildogthebirdsaresiliiliilthetreethelatureisharmoliousghatsthebirstproblemobalolliledudieitsaplusbproblemilzommolevzeptsphereolliledudiethisproblemgillbethebirstproblemobmostobtheolliledudiesthedatalimitatiolsaremultipletestzasesallthelumbersareseparatedbysomeghitespazesaaldbareilteiersaldlessthalmavloliiltilzorzpluspluslaliuaietheilputbilegilllessthalbourmeiabytesihopeyouzalsolveitasbastaspossiblebezauseitsveryveryeasyaldthetestzasesareverygeawbutibyouiotgatleyougillgorwboralolitimetobildthemistaweobyourproirampossiblyeldoythisproblem

Setelah dilakukan observasi, terdapat kata veryeasydustliwetheproblem. Diduga kata yang tepat adalah veryeasyjustliketheproblem. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihavetoldyouthatthisproblemisveryeasyjustliketheproblemlibetheuliversealdeverythiliyesitsveryeasybutyougillhavesometroubletoietazzeptedibyoudoltzaregiththeproblemdeszriptiolaveryeasyproblemislotalgaysaveryboriliproblemsometimesitgillbeilterestilibromthetimeyoutryittothetimeyousolveitbezauseabterlotsobgatleyougillbeelverygellthesulisshililioutsidethegildogthebirdsaresiliiliilthetreethelatureisharmoliousghatsthebirstproblemobalollilejudieitsaplusbproblemilzommolevzeptsphereollilejudiethisproblemgillbethebirstproblemobmostobtheollilejudiesthedatalimitatiolsaremultipletestzasesallthelumbersareseparatedbysomeghitespazesaaldbareilteiersaldlessthalmavloliiltilzorzpluspluslaliuaietheilputbilegilllessthalbourmeiabytesihopeyouzalsolveitasbastaspossiblebezauseitsveryveryeasyaldthetestzasesareverygeakbutibyouiotgatleyougillgorkboralolitimetobildthemistakeobyourproirampossiblyeljoythisproblem

Setelah dilakukan observasi, terdapat kata theproblemlibetheuliversealdeverythili. Diduga kata yang tepat adalah theproblemlifetheuniverseandeverything. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihavetoldyouthatthisproblemisveryeasyjustliketheproblemlifetheuniverseandeverythingyesitsveryeasybutyougillhavesometroubletogetazzeptedifyoudontzaregiththeproblemdeszriptionaveryeasyproblemisnotalgaysaveryboringproblemsometimesitgillbeinterestingfromthetimeyoutryittothetimeyousolveitbezauseafterlotsofgatleyougillfeelverygellthesunisshiningoutsidethegindogthebirdsaresinginginthetreethenatureisharmoniousghatsthefirstproblemofanonlinejudgeitsaplusbprobleminzommonevzeptsphereonlinejudgethisproblemgillbethefirstproblemofmostoftheonlinejudgesthedatalimitationsaremultipletestzasesallthenumbersareseparatedbysomeghitespazesaandbareintegersandlessthanmavlongintinzorzpluspluslanguagetheinputfilegilllessthanfourmegabytesihopeyouzansolveitasfastaspossiblebezauseitsveryveryeasyandthetestzasesareverygeakbutifyougotgatleyougillgorkforalongtimetofindthemistakeofyourprogrampossiblyenjoythisproblem

Setelah dilakukan observasi, terdapat kata yougillhavesometroubletogetazzepted. Diduga kata yang tepat adalah youwillhavesometroubletogetaccepted. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihavetoldyouthatthisproblemisveryeasyjustliketheproblemlifetheuniverseandeverythingyesitsveryeasybutyouwillhavesometroubletogetacceptedifyoudontcarewiththeproblemdescriptionaveryeasyproblemisnotalwaysaveryboringproblemsometimesitwillbeinterestingfromthetimeyoutryittothetimeyousolveitbecauseafterlotsofwatleyouwillfeelverywellthesunisshiningoutsidethewindowthebirdsaresinginginthetreethenatureisharmoniouswhatsthefirstproblemofanonlinejudgeitsaplusbproblemincommonevceptsphereonlinejudgethisproblemwillbethefirstproblemofmostoftheonlinejudgesthedatalimitationsaremultipletestcasesallthenumbersareseparatedbysomewhitespacesaandbareintegersandlessthanmavlongintincorcpluspluslanguagetheinputfilewilllessthanfourmegabytesihopeyoucansolveitasfastaspossiblebecauseitsveryveryeasyandthetestcasesareveryweakbutifyougotwatleyouwillworkforalongtimetofindthemistakeofyourprogrampossiblyenjoythisproblem

Setelah dilakukan observasi, terdapat kata problemincommonevcepts. Diduga kata yang tepat adalah problemincommonexcepts. Bila dilakukan decrypt terhadap maka akan diperoleh:

ihavetoldyouthatthisproblemisveryeasyjustliketheproblemlifetheuniverseandeverythingyesitsveryeasybutyouwillhavesometroubletogetacceptedifyoudontcarewiththeproblemdescriptionaveryeasyproblemisnotalwaysaveryboringproblemsometimesitwillbeinterestingfromthetimeyoutryittothetimeyousolveitbecauseafterlotsofwatleyouwillfeelverywellthesunisshiningoutsidethewindowthebirdsaresinginginthetreethenatureisharmoniouswhatsthefirstproblemofanonlinejudgeitsaplusbproblemincommonexceptsphereonlinejudgethisproblemwillbethefirstproblemofmostoftheonlinejudgesthedatalimitationsaremultipletestcasesallthenumbersareseparatedbysomewhitespacesaandbareintegersandlessthanmaxlongintincorcpluspluslanguagetheinputfilewilllessthanfourmegabytesihopeyoucansolveitasfastaspossiblebecauseitsveryveryeasyandthetestcasesareveryweakbutifyougotwatleyouwillworkforalongtimetofindthemistakeofyourprogrampossiblyenjoythisproblem

Didapat pemetaan huruf dari encrypted menjadi decrypted sebagai berikut:
a => i
b => f
c => p
d => j
e => b
f => s
g => w
h => y
i => g
j => r
k => d
l => n
m => m
n => t
o => a
p => m
q => v
r => r
s => u
t => h
u => e
v => x
w => k
x => o
y => l
z => c

*/