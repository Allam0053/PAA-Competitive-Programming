#include <iostream>
using namespace std;

int main() {
	char old_encrypt[] = "atoqunxykhxsntonntafcjxeyupafqujhuofhdsfnyawuntucjxeyupyabuntuslaqujfuolkuqujhntalihufanfqujhuofhesnhxsgayytoqufxpunjxseyunxiunozzucnukabhxskxlnzojugantntucjxeyupkufzjacnaxloqujhuofhcjxeyupaflxnoygohfoqujhexjalicjxeyupfxpunapufangayyeualnujufnalibjxpntunapuhxsnjhannxntunapuhxsfxyquaneuzosfuobnujyxnfxbgonyuhxsgayybuuyqujhguyyntufslafftalalixsnfakuntugalkxgntueajkfojufalialialntunjuuntulonsjuaftojpxlaxsfgtonfntubajfncjxeyupxbolxlyaludskiuanfocysfecjxeyupalzxppxluvzucnfctujuxlyaludskiuntafcjxeyupgayyeuntubajfncjxeyupxbpxfnxbntuxlyaludskiufntukonoyapanonaxlfojupsynacyunufnzofufoyyntulspeujfojufucojonukehfxpugtanufcozufoolkeojualnuiujfolkyuffntolpovyxlialnalzxjzcysfcysfyolisoiuntualcsnbayugayyyuffntolbxsjpuioehnufatxcuhxszolfxyquanofbofnofcxffaeyueuzosfuanfqujhqujhuofholkntunufnzofufojuqujhguowesnabhxsixngonyuhxsgayygxjwbxjoyxlinapunxbalkntupafnowuxbhxsjcjxijopcxffaeyhuldxhntafcjxeyup";
  char new_decrypt[894];
  char map_old[] = "abcdefghijklmnopqrstuvwxyz";
  char map_new[] = "ifpjbswygrdnmtamvruhexkolc";

  for(int it1=0; it1<894; it1++) {
    for(int it2=0; it2<27; it2++) {
      if (old_encrypt[it1] == map_old[it2]){
        new_decrypt[it1] = map_new[it2];
        continue;
      }
    }
  }

  printf("%s\n", new_decrypt);
	
	return 0;
}
// ntu => the
//cjxeyup => problem
//af => is
//o => a
//q => v
//h => y
//ks => du
//d j
//w k

//b f
//l n
//i g

//g w
//z c

//v x