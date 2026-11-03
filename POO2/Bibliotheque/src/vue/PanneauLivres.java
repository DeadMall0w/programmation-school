package src.vue;

import java.awt.BorderLayout;
import java.util.List;
import java.awt.Color;

import javax.swing.BorderFactory;
import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import src.modele.Livre;

public class PanneauLivres extends JPanel {
	private final DefaultListModel<Livre> modele = new DefaultListModel<>();

	public PanneauLivres(List<Livre> livres) {
		super(new BorderLayout());
		setBackground(new Color(247, 201, 62));
		setBorder(BorderFactory.createMatteBorder(1, 1, 0, 1, Color.BLACK));

		mettreAJourLivres(livres);
		JList<Livre> liste = new JList<>(modele);
		liste.setBackground(new Color(247, 201, 62));
		JScrollPane defilement = new JScrollPane(liste);
		defilement.getViewport().setBackground(Color.YELLOW);
		add(defilement, BorderLayout.CENTER);
	}

	public void mettreAJourLivres(List<Livre> livres) {
		modele.clear();
		for (Livre livre : livres) {
			modele.addElement(livre);
		}
	}
}
