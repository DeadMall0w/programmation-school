-- phpMyAdmin SQL Dump
-- version 5.2.1deb3
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mar. 06 mai 2025 à 21:55
-- Version du serveur : 8.0.41-0ubuntu0.24.04.1
-- Version de PHP : 8.3.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";

--
-- Base de données : `minutes`
--

-- --------------------------------------------------------

--
-- Structure de la table `champs_minutes`
--

CREATE TABLE `champs_minutes` (
  `id` int NOT NULL,
  `idMinutes` int NOT NULL,
  `idChamp` int NOT NULL,
  `valeur` varchar(100) NOT NULL
) ENGINE=InnoDB ;

-- --------------------------------------------------------

--
-- Structure de la table `champs_templates`
--

CREATE TABLE `champs_templates` (
  `id` int NOT NULL,
  `idProjet` int NOT NULL,
  `nom` int NOT NULL,
  `type` varchar(20) NOT NULL,
  `possibles` varchar(200) DEFAULT NULL
) ENGINE=InnoDB ;

-- --------------------------------------------------------

--
-- Structure de la table `membres`
--

CREATE TABLE `membres` (
  `id` int NOT NULL,
  `idProjet` int NOT NULL,
  `idMembre` int NOT NULL
) ENGINE=InnoDB ;

--
-- Déchargement des données de la table `membres`
--

INSERT INTO `membres` (`id`, `idProjet`, `idMembre`) VALUES
(1, 1, 2),
(2, 1, 5),
(3, 2, 6),
(4, 2, 1);

-- --------------------------------------------------------

--
-- Structure de la table `minutes`
--

CREATE TABLE `minutes` (
  `id` int NOT NULL,
  `idProjet` int NOT NULL,
  `idAuteur` int NOT NULL
) ENGINE=InnoDB ;

-- --------------------------------------------------------

--
-- Structure de la table `projets`
--

CREATE TABLE `projets` (
  `id` int NOT NULL,
  `idCreateur` int NOT NULL,
  `nom` varchar(100) NOT NULL
) ENGINE=InnoDB ;

--
-- Déchargement des données de la table `projets`
--

INSERT INTO `projets` (`id`, `idCreateur`, `nom`) VALUES
(1, 1, 'cmj'),
(2, 2, 'aap');

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `id` int NOT NULL,
  `pseudo` varchar(100) COLLATE utf8mb4_general_ci NOT NULL,
  `pass` varchar(100) COLLATE utf8mb4_general_ci NOT NULL,
  `role` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL DEFAULT 'user'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`id`, `pseudo`, `pass`, `role`) VALUES
(1, 'tom', 'web', 'admin'),
(2, 'max', 'bdd', 'admin'),
(3, 'toto', 'toto', 'user'),
(5, 'nico', 'nico', 'user'),
(6, 'anis', 'anis', 'user');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `champs_minutes`
--
ALTER TABLE `champs_minutes`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `champs_templates`
--
ALTER TABLE `champs_templates`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `membres`
--
ALTER TABLE `membres`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `minutes`
--
ALTER TABLE `minutes`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `projets`
--
ALTER TABLE `projets`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `champs_minutes`
--
ALTER TABLE `champs_minutes`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `champs_templates`
--
ALTER TABLE `champs_templates`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `membres`
--
ALTER TABLE `membres`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `minutes`
--
ALTER TABLE `minutes`
  MODIFY `id` int NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `projets`
--
ALTER TABLE `projets`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `id` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;
COMMIT;
