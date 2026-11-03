package src.vue;

import java.awt.BorderLayout;
import java.awt.Color;
import java.util.List;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingWorker;
import javax.swing.border.Border;
import java.util.concurrent.ExecutionException;

import src.modele.Livre;
import src.requete.RequeteBiblio;

public class FenetreBiblio extends JFrame {

    private final PanneauLivres panneauLivres;
    private final PanneauEmprunt panneauEmprunt;
    private final RequeteBiblio requeteBiblio;
    private final JTextField champRecherche = new JTextField(30);

    public FenetreBiblio(List<Livre> livres, RequeteBiblio requeteBiblio, String motCleInitial) {
        super("Bibliotheque municipale");
        setLayout(new BorderLayout());

        this.requeteBiblio = requeteBiblio;
        champRecherche.setText(motCleInitial);
        champRecherche.addActionListener(event -> rechercherLivres());
        panneauLivres = new PanneauLivres(livres);
        panneauEmprunt = new PanneauEmprunt();

        getContentPane().setBackground(new Color(247, 201, 62));
        initialiserDisposition();
        setSize(900, 450);
        setLocationRelativeTo(null);
    }

    private void initialiserDisposition() {
        add(creerPanneauRecherche(), BorderLayout.NORTH);
        add(panneauLivres, BorderLayout.CENTER);
        add(panneauEmprunt, BorderLayout.SOUTH);
    }

    private JPanel creerPanneauRecherche() {
        JPanel recherche = new JPanel();
        recherche.setBackground(new Color(247, 201, 62));
        recherche.setBorder(creerBordureElement());
        recherche.add(new JLabel("Recherche :"));
        recherche.add(champRecherche);
        return recherche;
    }

    private void rechercherLivres() {
        String motCle = champRecherche.getText().trim();
        champRecherche.setEnabled(false);

        new SwingWorker<List<Livre>, Void>() {
            @Override
            protected List<Livre> doInBackground() throws Exception {
                return requeteBiblio.getLivresParMotCle(motCle);
            }

            @Override
            protected void done() {
                try {
                    panneauLivres.mettreAJourLivres(get());
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    JOptionPane.showMessageDialog(FenetreBiblio.this,
                            "La recherche a ete interrompue.", "Erreur", JOptionPane.ERROR_MESSAGE);
                } catch (ExecutionException e) {
                    JOptionPane.showMessageDialog(FenetreBiblio.this,
                            "Impossible de rechercher les livres : " + e.getCause().getMessage(),
                            "Erreur", JOptionPane.ERROR_MESSAGE);
                } finally {
                    champRecherche.setEnabled(true);
                }
            }
        }.execute();
    }

    private Border creerBordureElement() {
        return BorderFactory.createMatteBorder(1, 1, 0, 1, Color.BLACK);
    }
}
