package src.vue;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Color;

import javax.swing.BorderFactory;
import javax.swing.JPanel;

public class PanneauEmprunt extends JPanel {

	public PanneauEmprunt() {
		super(new BorderLayout());
		setBackground(new Color(247, 201, 62));
		setBorder(BorderFactory.createMatteBorder(1, 1, 0, 1, Color.BLACK));
		setPreferredSize(new Dimension(0, 100));
	}
}
