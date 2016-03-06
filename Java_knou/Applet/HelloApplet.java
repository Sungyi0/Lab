import java.awt.*;
import java.applet.*;

public class HelloApplet extends Applet {
	TextArea ta = null;
	public HelloApplet() {
		setLayout(new BorderLayout());
		ta = new TextArea();
		add(ta, BorderLayout.CENTER);
	}
	
	public void init() {
		StringBuffer szMsg = new StringBuffer();
		szMsg.append("init() is invoked.\n");
		szMsg.append(getCodeBase().toString()).append("\n");
		szMsg.append(getLocale().toString()).append("\n");
		ta.append(szMsg.toString());
	}
	
	public void start() {
		ta.append("start() is invoked.\n");
	}
	
	public void stop() {
		System.out.println("stop() is invoked. \n");
	}

	public void destroy() {
		System.out.println("destroy() is invoked.\n");
	}
}