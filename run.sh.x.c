#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -r -T -f ./run.sh 
#endif

static  char data [] = 
#define      shll_z	8
#define      shll	((&data[2]))
	"\033\020\273\322\112\323\171\367\325\131"
#define      pswd_z	256
#define      pswd	((&data[21]))
	"\347\244\314\353\207\260\201\112\337\336\123\033\333\020\100\233"
	"\306\200\371\331\364\330\211\376\174\337\300\163\174\070\332\362"
	"\021\316\106\327\351\345\102\032\006\325\066\341\345\167\175\254"
	"\367\166\206\354\117\017\353\313\357\253\077\154\344\031\136\365"
	"\350\245\315\321\212\017\354\220\344\043\162\312\232\360\167\222"
	"\147\375\177\267\015\152\202\374\025\301\150\371\333\306\357\304"
	"\154\274\225\366\313\202\207\260\246\372\173\100\352\362\322\122"
	"\360\121\011\375\274\214\371\321\116\142\313\051\051\272\356\225"
	"\167\204\214\102\006\024\363\254\016\156\355\371\140\300\114\121"
	"\022\125\116\316\341\110\237\057\252\153\131\323\046\107\151\235"
	"\313\365\337\322\011\323\177\030\101\154\022\242\054\136\363\076"
	"\264\101\015\225\211\254\305\064\030\037\010\076\147\161\333\063"
	"\147\273\006\161\216\205\211\317\362\234\161\037\373\145\136\257"
	"\246\153\105\060\030\013\144\060\052\155\156\222\336\111\305\106"
	"\005\314\267\223\121\101\143\104\335\325\143\330\072\301\210\341"
	"\055\315\021\105\331\166\165\003\343\344\226\302\056\134\011\063"
	"\050\300\307\172\001\052\276\337\000\041\270\023\006\024\332\200"
	"\025\005\076\364\005\140\255\100\104\355\134\125\374\212\253\344"
#define      date_z	1
#define      date	((&data[298]))
	"\266"
#define      rlax_z	1
#define      rlax	((&data[299]))
	"\226"
#define      msg1_z	42
#define      msg1	((&data[300]))
	"\157\266\152\113\046\361\377\062\003\037\072\215\333\134\336\174"
	"\103\045\277\070\020\216\215\043\020\337\202\112\363\104\345\113"
	"\230\132\377\027\241\336\276\133\362\267\124\033"
#define      inlo_z	3
#define      inlo	((&data[344]))
	"\143\057\367"
#define      opts_z	1
#define      opts	((&data[347]))
	"\051"
#define      chk2_z	19
#define      chk2	((&data[350]))
	"\125\040\133\321\120\072\253\314\023\172\275\313\253\254\051\171"
	"\256\020\000\251\320"
#define      xecc_z	15
#define      xecc	((&data[371]))
	"\235\357\157\013\343\322\121\201\050\055\342\343\005\063\230\112"
	"\164"
#define      lsto_z	1
#define      lsto	((&data[386]))
	"\273"
#define      tst1_z	22
#define      tst1	((&data[389]))
	"\276\014\122\147\161\017\322\266\226\046\232\157\113\233\011\376"
	"\270\360\122\123\370\272\021\242"
#define      chk1_z	22
#define      chk1	((&data[411]))
	"\265\315\207\335\057\202\121\254\223\041\364\125\065\231\005\375"
	"\244\350\340\352\153\370"
#define      msg2_z	19
#define      msg2	((&data[434]))
	"\136\044\331\034\322\370\304\007\061\252\272\371\333\174\173\326"
	"\245\353\327\367\166"
#define      text_z	120
#define      text	((&data[464]))
	"\111\117\042\275\120\170\336\221\022\354\166\315\343\113\342\106"
	"\152\321\257\366\120\016\135\132\152\256\277\271\253\045\124\177"
	"\110\206\315\234\102\323\165\221\207\374\155\242\262\116\205\106"
	"\075\323\127\205\333\347\245\212\373\045\211\063\232\352\251\341"
	"\243\102\141\024\254\324\071\225\235\022\261\371\244\320\230\227"
	"\020\330\112\204\366\012\231\367\107\073\164\211\325\346\047\171"
	"\113\132\237\203\072\143\301\207\356\130\242\123\164\056\147\350"
	"\132\230\240\150\335\142\003\262\047\046\343\115\115\063\156\050"
	"\076\143\057\001\367\127\234"
#define      tst2_z	19
#define      tst2	((&data[592]))
	"\245\272\352\014\022\374\001\110\051\001\017\344\124\306\334\051"
	"\312\231\342\251\110\272\265\310\056"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	1	/* Define as 1 to enable ptrace the executable */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask  = (unsigned long)&chkenv;
	mask ^= (unsigned long)getpid() * ~mask;
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

#if !defined(TRACEABLE)

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
#	define PTRACE_ATTACH	PT_ATTACH
#endif
void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PTRACE_ATTACH, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !defined(TRACEABLE) */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = argv[0];

	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	ret = chkenv(argc);
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
	varg[j++] = argv[0];		/* My own name at execution */
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !defined(TRACEABLE)
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
