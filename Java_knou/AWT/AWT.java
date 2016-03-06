import java.awt.*;
import java.awt.event.*;

public class AWT extends Frame {
	Label msg = null;
	Panel msgPanel = null, commandPanel = null;
	Button yesButton = null, noButton = null, cancelButton = null;
	
	public AWT() {
		setTitle("Panel Test");
		msgPanel = new Panel();
		commandPanel = new Panel();
		
		msg = new Label("Hello!");
		msg.setEnabled(false);
		msgPanel.add(msg);
		yesButton = new Button("yes");
		noButton = new Button("no");
		cancelButton = new Button("cancel");
		
		commandPanel.add(yesButton);
		commandPanel.add(noButton);
		commandPanel.add(cancelButton);
		
		add("Center", msgPanel);
		add("South", commandPanel);
		
		setSize(300, 100);
	}

	public static void main(String args[]) {
		AWT pt = new AWT();
		pt.setVisible(true);
	}
}