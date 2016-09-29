#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "func.c"
#include "pfdecipher.h"

char *wordlist;
tetra *table;
size_t table_len;
double trivial_value;

char ctxt[] = "OGIUEGPTKHHNDHXBHDHZYNITKNMUFUKODKEYTSXIIATHKNZDLWCGTWBXKNEIFUKODKNLKNPBENFMSKNKNTSPBPSPPGPVFUKODKTUVWIOIXHNWTPZEWQNNANGNLZPDSHVZGOUSHPTGNGCDGHLVWIHWXETFCMUGNGZTMIUOIHTHVEHOIQPMHDHOIZYUBUEWUDKUESPLWWISPBPSPTENVYNUEEYMHVTXICWDWUSFKDKTUVPDTWUITDHNGPUNEMUHSNKWETSHNTELYNHFMZUNGFMQPPDTMVUPZFHLFTHOIKNTCKNSTKCMFPVFEWMPTGNDPFYQYDTSYPUYUSTFHCENKNLXNFAHVCHDSGZIQTEMHKNSEIRHNWNDXVHANBQZULWNGILKDZUSWKNTCCNDWNVMFHVMHLUGNITOILQYBHAOUSEFUKODKTUVUXWIWPDXFSMSHPNLNTCKMBXHNWSUFGCCKWOWIYNEHBXPLFKDKEYLWWDILFYFQUISDGCWVTUYOTHHGIKTHUBHEUWWMUBUEEHNTBYSMWSOITLMUKNSTKICWTSKFHBOIKICKCNOHIHAPPLFKDKLWDTSHZKGUSEKHHNWSIMEHUIWMGCSGPTGKCPPVWVGCNGGSWELWCGTWSPBPSPFUKODKTUWUFEFXWVFUKODKTUMPVPTUGOUEMHDHFUKODKDPFWYWPASTFHLCXBEKNTLEMHTHFUKODKHVEHCOFLSDSTHNWTHVXICWSPBPSPGLHNNGLQCIEHVHOIYLWRTUWUHECBGUSHDPBZWVMIUMTSXUPQPSFKDKHNWMYNHTCGSTGLUEOIAWIMSHNTYNFYQITHMWTSGZFYQYIMFNSMFWLQFKDKHNTHPTASNTVPFOFMFUKHGZTWCHMHDHOIKZNUEWHNWNHZYBKXDHHNWVTWLQFKDKHNTELWEWHPYBEWYBSHNTXNFYFIDLFKDKHNWMFOUMWVYNFYFLNVXIUENGDGCTFIEWWICGUELQPUWVNKNGDGLNWPFYWLFPFUKODKXUTHULGCFUKODKTUWUGNSEYUHVVDWVNKOLWSGKFOUMTUEUUNSWMUGNSMSGUWUWSHDGSHKNNVLNOSICTUVMULTMAPIHKFHVMUGNMIICADFKDTUEWLEWNTHVFUKODKTUEUWEVHMUTUXWBXWMXBITFUKODKTUWCDTAPIQKDWSTELQFKDKNVPCGNCOFYWLSMFUKODKTUEPZDTELWEWHYGUYVNTIOKIKNCWFUKODKTUAPFYSGPTHEBXKNSKYNITMUGNSHPTKEFKTSGNMFYZZDDTFYFWXLYBTSECTUVPWSZGOUSEMFHZNTBYGLFAWVSTFHCTUEDCFHETEUTELQFKDKTUWUIQTEETEANTDVNKHNWHWUEUNKTOIMHNZGONSWFHETEANTDVNKHNWHMWSHHNWNPZUZUEUIWVDGPGFYCIUSUILQOUNCFMEYZGULFKDKCKPZDGILSHPTAHDTSDCOQWLWCGTWFUKODKDGCEUOITMFHZNTVONAUWUWNGFUKODKTUWUGLENWVHNZGULUBCWSWKHHNWDTOIMHNZGNYPAMUSTNGFUKODKNVDPNCWNDGSHWVKNDKTMHNWDPTRPRXMUGNDGLTUOITUIHNOIGOITGDGPGCSGNTETZYTUADFKDKHTUEVHHNUBTYHEFUKODKEYTSWXHVEWYBWMTCQBFXTSOICUUIIRTCYHLWCYUYOIZWUOSDQPILITUBGZFYQYLYNHFUKODKCNPQFKDKOWPDFKOIALFKDKOWPDFKOIAWNKNGCTFYQYLYNHFUKODKCNPVUIGHUBNVOITPBPHXMUGNFIFXWVCUFUKODKTUECGDTUIFVUGCEPDTVWVDTUXNORIQOIKZQPNFEHNTSPBPSPPGPVKNDGPVFEDSFKDKDPHPHXOIKZPNTWNBUSXNMXWHLNSNNLPTUEHNZGENFOFXTUWUOIYWWVZGWEVHHLHTUANKOWNKOUSTEPOWGDGPGLHNLNSWSHWUTINGPLFKDKNBHNTEGNFYCGVETUSDADFKDKLQHVDSYNITUBKHHNWMYNSWOWPDFKOIALFKDKCNPQFKDKOWPDFKOIAWNKOWGCNGGSWSKDWVNKUGOIGZFHCHHXTCOBETEAUNWVNKHNNLDGPLFKDKCNPVNKKIGDGPFUKODKXIODNLVHZUSWIFVDTUFUKODKNLGUMPMUGNEWFUDWTCFNUITCULUBCWFUKODKCNPQFKDKNTHVYCNWMPMUKEXWNLLNESWEVHETWHUBGNFYWLNCKHHNNLWOIBHTMUGHUBMFFYFIMDDSFKDKCNPVNKKIGDGPFUKODKBYDHDTHTWCDTEWDWNVMFHVLYTHBMVHHNWMGCFQFKDKTUECCGXPXICANKNTETWDWVCNHRYBETMPMUAEUIGHUBDGSHKNETTHNTKNVOENTEGUMPMUHSUFFKDKUGSEMWHVADFKDKUWUIAENKLGTUKHKNEHUXNTHVFUKODKSWTUOIAIUPKZOIEHHNNLZYNGGHIFVMGCCWNKKIGDGPFUKODKTUMPMUSHWUEHBPOVWVNKUGDFXNFACOFYFIQODTNAOLICTUEUUNSWHNUBTYHEFUKODKTUWUDGSHKNEHUXWLTMNGFUKODKNVDPNCWNKSMHWSESULDTUEKIUMMUAEUIGHUBFUDWMFIFOIKZNUNAFUKODKDKGOITDWDKADFKDKSPBWILITGDGPGCFWRITHHTXQMHWSOITLGLHNHNNLLNFYWIKNVOEHUITSUIETSEMNLXUBHQ";

char realtxt[] = "iknowthatxtheproperthingtodocomxmawhenyougettoavillageortowncomxmaistorushofftothechurchyardcomxmaandenioythegravesbutitisarecreationthatialwaysdenymyselfdotitakenointerestincrexepingrounddimandchillychurchesbehindwhexezyoldmencommaandreadingepitaphsdotnoteventhesightofabitofcrackedbrasxsletintoastoneaffordsmewhaticalxlrealhappinesxsdotishockrespectablesextonsbytheimperturbabilityiamabletoassumebeforeexcitinginscriptionscomxmaandbymylackofenthusiasmforthelocalfamilyhistorycommawhilemyilxlconcealedanxietytogetoutsidewoundstheirfeelingsdotonegoldenmorningofasunxnydaycommaileantagainstxthelowstonewallthatguardedalittlevillagechurchcomxmaandismokedcomxmaandxdrankindexepcomxmacalmgladnesxsfromtheswexetcomxmarestfulscenethegreyoldchurchwithitsclusteringivyanditsquaintcarvedwoodenporchcommathewhitelanewindingdownthehilxlbetweentalxlrowsofelmscommathethatchedroxofcotxtagespexepingabovetheirtrimkepthedgescommathesilverxriverintheholxlowcommathewoxodedhilxlsbeyonditwasalovelylandscapedotitwasidylxlicxcomxmapoeticalcomxmaanditinspiredmedotifeltgoxodandnobledotifeltididntwanttobesinfulandwickedanymoredotiwouldcomeandliveherecomxmaandneverdoanymorewrongcomxmaandleadablamelesscommabeautifulxlifecomxmaandhavesilverhairwhenigotoldcomxmaandalxlthatsortofthingdotinthatmomentiforgavealxlmyfriendsandrelationsfortheirwickednesxsandcusxsednesscommaandiblessedthemdottheydidnotknowthatiblesxsedthemdottheywenttheirabandonedwayalxlunconsciousofwhaticommafarawayinthatpeacefulvillagecomxmawasdoingforthembutididitcomxmaandiwishedthaticouldletxthemknowthatihaddoneitcomxmabecauseiwantedtomakethemhapxpydotiwasgoingonthinkingawayallthesegrandcommatenderthoughtscomxmawhenmyreveriewasbrokeninuponbyashrillpipingvoicecryingoutalxlrightcomxmasurcommaimacomingcommaimacomingdotitsalxlrightcomxmasurdontyoubeinahurrydotilookedupcomxmaandsawanoldbaldheadedmanhobxblingacrossthechurchyardtowardsmecommacarxryingahugebunchofkeysinhishandthatshoxokandiingledateverystepdotimotionedhimawaywithsilentdignitycommabuthestilxladvancedcommascreechingoutxthewhileimacomingcommasurcommaimacomingdotimalittlelamedotiaintasxspryasiusedtobedotthiswaycommasurdotgoawaycomxmayoumiserableoldmancomxmaisaidxdotivecomeassoonasicouldcomxmasurcommaherepliedxdotmymissisneverseeyoutilxliustxthisminutedotyoufolxlowmecommasurdotgoawaycomxmairepeatedleavemebeforeigetoverthewallcommaandslayxyoudotheseemedsurprisedxdotdontyouwanttoseethetombshesaidxdotnocommaiansweredcommaidontdotiwantxtostopherecomxmaleaningupagainstthisgrittyoldwalldotgoawaycomxmaandxdontdisturbmedotiamchockfulxlofbeautifulandnoblethoughtscomxmaandiwanttostoplikeitcomxmabecauseitfexelsniceandgooddotdontyoucomefoolingaboutcomxmamakingmemadcommachivyingawayallmybetterfexelingswiththissilxlytombstonenonsenseofyours";


int main(int argc, char **argv)
{
    srand(time(0));
    makeLowerCase(ctxt, strlen(ctxt));
    //initialize_wordlist("wordlist.txt");
    initialize_tetragram("quadgrams.txt");
    
    double realscore = test(realtxt, strlen(realtxt));
    printf("realscore is %f\n", realscore);
    
    /*
    char *somestring = "tion";
    printf("score is %f\n", test(somestring, strlen(somestring)));
    */
/*
    char trialkey[] = "thavpdrwfmcnekyuiobqlgsxz";
    char *trialtxt = apply(trialkey);
    int trialscore = test(trialtxt, strlen(trialtxt));
    puts(trialtxt);
    printf("trialscore: %d\n", trialscore);
    free(trialtxt);
*/
    
    char bestkey[26];
    random_key(bestkey);
    char *ptxt = calloc(strlen(ctxt) + 1, sizeof(char));
    apply(bestkey, ptxt);
    double bestscore = test(ptxt, strlen(ptxt));
    free(ptxt);
    char key1[26];
    char key2[26];
    double score1;
    double score2;
    char *ptxt1 = calloc(strlen(ctxt) + 1, sizeof(char));
    char *ptxt2 = calloc(strlen(ctxt) + 1, sizeof(char));

    int i, j;
    char temp;
    int goon = TOLERATE;
    int counter = 0;
    while (goon) {
    L2:
        if (counter % 5 == 0)
            print_calc_counter(counter, bestscore);
        counter++;
        
        memcpy(key1, bestkey, 26);
        memcpy(key2, bestkey, 26);
        
        //random_shift(key1);
        modify_key(bestkey, key1, dia_shift);
        apply(key1, ptxt1);
        score1 = test(ptxt1, strlen(ptxt1));

        random_swap(key2);
        apply(key2, ptxt2);
        score2 = test(ptxt2, strlen(ptxt2));
        
        if (score1 > bestscore) {
            if (score2 > score1) {
                memcpy(bestkey, key2, 25);
                bestscore = score2;
                putc('b',stdout);
            } else {
                memcpy(bestkey, key1, 25);
                bestscore = score1;
                putc('a',stdout);
            }
            goon = TOLERATE;
        } else {
            if (score2 > bestscore) {
                memcpy(bestkey, key2, 25);
                bestscore = score2;
                goon = TOLERATE;
                putc('b',stdout);
            } else {
                if (!(--goon)) {
                    puts("brute force kicks in");
                    for (i = 0; i < 25; i++) {
                        for (j = i+1; j < 25; j++) {
                            
                            if (counter % 5 == 0)
                                print_calc_counter(counter, bestscore);
                            counter++;
                            
                            memcpy(key2, bestkey, 25);
                            key2[i] = bestkey[j];
                            key2[j] = bestkey[i];
                            apply(key2, ptxt2);
                            score2 = test(ptxt2, strlen(ptxt2));
                            if (score2 > bestscore) {
                                memcpy(bestkey, key2, 25);
                                bestscore = score2;
                                goon = TOLERATE;
                                puts("brute force stops");
                                goto L2;
                            }
                        }
                    }                                                
                }
            }
        }
    }
    free(ptxt1);
    free(ptxt2);
    
    printf("looped %d times\nbestscore: %f\nkey found:\n", counter, bestscore);
    printkey(bestkey);
    
    char *plain_txt = (char *)calloc(strlen(ctxt)+1, sizeof(char));
    apply(bestkey, plain_txt);
    puts(plain_txt);
    free(plain_txt);
}

void print_calc_counter(int counter, double bestscore) {
    printf("%d-th calculation\tcurrent bestscore is %f\n", counter, bestscore);
}


void printkey(char *key)
{
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            putc(key[i * 5 + j], stdout);
        }
        putc('\n', stdout);
    }
}

void random_swap(char *key)
{
    int num1 = rand() % 25;
    int num2 = rand() % 25;
    char temp = key[num1];
    key[num1] = key[num2];
    key[num2] = temp;
}

void random_shift(char *key)
{
    int roworcol = rand()%2; // 0 for row, 1 for col
    int num1 = rand()%5; // first row or col number to shift
    int num2;
    while ((num2 = rand()%5) == num1); // second row or col number to shift
    int i;
    if (roworcol) {
        char temp;
        for (i = 0; i < 5; i++) {
            temp = key[i * 5 + num1];
            key[i * 5 + num1] = key[i * 5 + num2];
            key[i * 5 + num2] = temp;
        }
    } else {
        char temp[5];
        memcpy(temp, &key[num1 * 5], 5);
        memcpy(&key[num1 * 5], &key[num2 * 5], 5);
        memcpy(&key[num2 * 5], temp, 5);
    }
}


void modify_key(char *key, char *outcome, int *scheme) {
    int i;
    for (i = 0; i < 25; i++) {
        outcome[i] = key[scheme[i]-1];
    }
}

void random_key(char *key)
{
    char abc[25];
    int i;
    for (i = 0; i < 25; i++) {
        if (i < 'j' - 'a') {
            abc[i] = 'a' + i;
        } else if (i >= 'j' - 'a') {
            abc[i] = 'a' + i + 1;
        }
    }

    char used[25];
    int idx;
    memset(used, 0, 25);
    for (i = 0; i < 25; i++) {
        key[i] = abc[nth_zero(used, 25, rand()%(25-i) + 1)];
    }
    key[25] = 0;
}

/*
 * Return the index of the n-th (1-indexed) zero in the bit array, and set
 * that it to 1.
 * Used as a helper function of random_key(char *).
 */
size_t nth_zero(char *bits, int len, int n)
{
    int i, j;
    
    int temp = n;
    for (i = 0; i < 25; i++) {
        if (!bits[i]) {
            n--;
            if (!n) {
                bits[i] = '1';
                return i;                
            }
        }
    }
    
    return 0;
}
    
/*
 * Test the provided string and give a score on its likelyhood of being English.
 */

double test(char *str, int len) {
    int i, j;
    double total = 0;
    for (i = 0; i < len - 3; i++) {
        for (j = 0; j < table_len; j++) {
            
            if (str[i] == table[j].key[0] &&
                str[i+1] == table[j].key[1] &&
                str[i+2] == table[j].key[2] &&
                str[i+3] == table[j].key[3]) {
                total += table[j].log;
                break;
            }
        }
        if (j == table_len) {
            total += trivial_value;
        }
    }
    return total;
}

/* obsolete
int test(char *str, size_t len)
{
    int i, j, k, count;
    size_t wordlist_len = strlen(wordlist);
    count = 0;

    for (i = 0; i < len; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            continue;
    L1:
        for (j = 0; j < wordlist_len; j++) {
            if (str[i] == wordlist[j]) {
                k = i;
                while (1) {
                    k++;
                    j++;
                    
                    if (wordlist[j] == '\n') {                        
                        count++;
                        i = k;
                        goto L1;
                    }

                    if (wordlist[j] != str[k]) { 
                        while (wordlist[++j] != '\n' && j < wordlist_len);
                        break;
                    }
                }
            } else {
                while (wordlist[++j] != '\n' && j < wordlist_len);
            }
        }
    }
    
    return count;
}
*/

/*
 * Run deciphing function on ctxt using provided key.
 * Return the resulting text, which need to be freed by caller.
 */
void apply(char *key, char *ptxt)
{
    size_t len = strlen(ctxt);
    int i, idx1, idx2, col1, row1, col2, row2;    
    //char *ptxt = calloc(len+1, sizeof(char));
    for (i = 0; i < len; i++) {
        idx1 = getIdx(key, ctxt[i]);
        col1 = idx1 % 5;
        row1 = idx1 / 5;        
        idx2 = getIdx(key, ctxt[i+1]);
        col2 = idx2 % 5;
        row2 = idx2 / 5;
        
        if (row1 == row2) {
            ptxt[i] = key[row1*5+(col1+1)%5];
            ptxt[++i] = key[row2*5+(col2+1)%5];
        } else if (col1 == col2) {
            ptxt[i] = key[(row1+1)%5*5+col1];
            ptxt[++i] = key[(row2+1)%5*5+col2];
        } else {
            ptxt[i] = key[row1*5+col2];
            ptxt[++i] = key[row2*5+col1];
        }
    }
}
        

int getIdx(char *key, char c)
{
    int i;
    for (i = 0; i < 25; i++) {
        if (key[i] == c)
            return i;
    }
    printf("error when indexing character \"%c\" in key\n", c);
    return -1;
}

void initialize_tetragram(char *fname)
{
    FILE *fp = fopen(fname, "r");
    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    rewind(fp);
    char *file = (char *)calloc(filesize+1, sizeof(char));
    fread(file, filesize, 1, fp);
    fclose(fp);

    int i;
    int rows = 0;
    for (i = 0; i < filesize; i++) {
        if (file[i] == '\n')
            rows++;
    }

    table = (tetra *)calloc(rows, sizeof(tetra));
    table_len = rows;
    char temp[32];
    int j;
    double total;
    rows = 0;
    for (i = 0; i < filesize; i++) {
        table[rows].key[0] = file[i++] + 32;
        table[rows].key[1] = file[i++] + 32;
        table[rows].key[2] = file[i++] + 32;
        table[rows].key[3] = file[i++] + 32;
        i++;
        memset(temp, 0, 32);
        j = 0;
        while (file[i] != '\n') {
            temp[j++] = file[i++];
        }
        table[rows].log = atoi(temp);
        total += table[rows++].log;
    }
    
    for (i = 0; i < rows; i++) {
        table[i].log = log(table[i].log / total);
    }
    trivial_value = table[rows-1].log;
}

void print_table(tetra *table, size_t len)
{
    int i;
    puts("===============================");
    for (i = 0; i < len; i++) {
        printf("%s\t%f\n", table[i].key, table[i].log);
    }
}


/*
 * Load the dictionary file into memory, and get rid of all the
 * one-letter words.
 */
void initialize_wordlist(char *fname)
{
    FILE *fp;
    fp = fopen(fname, "r");

    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    rewind(fp);
    char *words = (char *)calloc(filesize+1, sizeof(char));
    
    fread(words, filesize, 1, fp);
    fclose(fp);

    int i, j;

    char *temp = (char *)calloc(filesize+1, sizeof(char));
    int isfirst = 0;
    j = 0;
    for (i = 0; i < filesize-1; i++) {
        // printf("i=%d\n",i);
        if (isfirst && words[i+1] == '\n') {
            i++;
        } else {
            temp[j++] = words[i];
            if (words[i] == '\n') {
                isfirst = 1;
            } else {
                isfirst = 0;
            }
        }
    }
    free(words);
    wordlist = temp;
}
