import java.util.*;
import java.io.*;

class No_Minimum_No_Maximum {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1_000_000_007, N, K;
	int[] arr;
	long[][] pascal;

	void build(int n) {
		pascal = new long[n+1][];
		for(int i=1;i<=n;i++) {
			pascal[i] = new long[i+1];
			pascal[i][0] = 1;
			pascal[i][i] = 1;
			for(int j=1;j<i;j++) pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
		}
	}

	int modPow(long b, int e) {
		long res = 1;
		while(e > 0) {
			if(e%2 == 1) res = res*b%mod;
			e /= 2;
			b = b*b%mod;
		}
		return (int)res;
	}

	long ncrmod(int n, int r) { return ((r < n-r) ? pascal[n][r] : pascal[n][n-r])%mod; }

	int get(int idx) {
		long res = 0;
		int lim = Math.min(idx, K-2);
		for(int i=1;i<=lim;i++)
			res = (res + (ncrmod(idx, i) * ncrmod(N-idx-1, K-i-1))%mod)%mod;
		
		return (int)res;
	}
	
	void solve() {
		build(2500);
		int T = ni();
		
		while(T-->0) {
			N = ni();
			K = ni();
			arr = na(N);
			Arrays.sort(arr);

			int[] freq = new int[N];
			int lim = (N%2 == 0) ? N/2-1 : N/2;
			for(int i=1;i<=lim;i++) {
				freq[i] = get(i);
				freq[N-i-1] = freq[i];
			}

			long res = 1;
			for(int i=1;i<N-1;i++)
				res = (res * modPow(arr[i], freq[i]))%mod;
			
			out.println(res);	//MAKE TEST CASE GENERATOR
		}
	}
	
	void run() throws Exception {
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		if (!INPUT.isEmpty()) {
			tr(System.currentTimeMillis() - s + "ms");
		}
	}

	public static void main(String[] args) throws Exception {
		new No_Minimum_No_Maximum().run();
	}

	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;

	private int readByte() {
		if (lenbuf == -1) {
			throw new InputMismatchException();
		}
		if (ptrbuf >= lenbuf) {
			ptrbuf = 0;
			try {
				lenbuf = is.read(inbuf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (lenbuf <= 0) {
				return -1;
			}
		}
		return inbuf[ptrbuf++];
	}

	private boolean isSpaceChar(int c) {
		return !(c >= 33 && c <= 126);
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isSpaceChar(b));
		return b;
	}

	private double nd() {
		return Double.parseDouble(ns());
	}

	private char nc() {
		return (char) skip();
	}

	private String ns() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private char[] ns(int n) {
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while (p < n && !(isSpaceChar(b))) {
			buf[p++] = (char) b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for (int i = 0; i < n; i++) {
			map[i] = ns(m);
		}
		return map;
	}

	private int[] na(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = ni();
		}
		return a;
	}

	private int ni() {
		int num = 0, b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private long nl() {
		long num = 0;
		int b;
		boolean minus = false;
		while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if (b == '-') {
			minus = true;
			b = readByte();
		}

		while (true) {
			if (b >= '0' && b <= '9') {
				num = num * 10 + (b - '0');
			} else {
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private void tr(Object... o) {
		if (INPUT.length() > 0) {
			System.out.println(Arrays.deepToString(o));
		}
	}
}