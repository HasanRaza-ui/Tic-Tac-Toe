void CComputerPlayer::makeMove(CBoard& board) {
    if (m_computerPlayer1) {
        // Computer is player 1
        if (makeWinningMove(board)) {
            return;
        } else if (blockOpponentWinningMove(board)) {
            return;
        }
    } else {
        // Computer is player 2
        if (blockOpponentWinningMove(board)) {
            return;
        } else if (makeWinningMove(board)) {
            return;
        }
    }

    // If no winning or blocking moves, make strategic moves
    if (makeMoveInCenter(board)) {
        return;
    } else if (makeMoveInCorner(board)) {
        return;
    } else {
        makeMoveInEdge(board);
    }
}

bool CComputerPlayer::makeWinningMove(CBoard& board) {
    if (board.checkForWinningMove(m_symbol)) {
        board.placeStone(board.getWinningMove().first, board.getWinningMove().second, m_symbol);
        return true;
    }
    return false;
}

bool CComputerPlayer::blockOpponentWinningMove(CBoard& board) {
    if (board.checkForWinningMove(board.getOpponentSymbol())) {
        board.placeStone(board.getWinningMove().first, board.getWinningMove().second, m_symbol);
        return true;
    }
    return false;
}

bool CComputerPlayer::makeMoveInCenter(CBoard& board) {
    if (!board.checkPosition(1, 1)) {
        board.placeStone(1, 1, m_symbol);
        return true;
    }
    return false;
}

bool CComputerPlayer::makeMoveInCorner(CBoard& board) {
    static const std::pair<int, int> corners[] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (const auto& corner : corners) {
        if (!board.checkPosition(corner.first, corner.second)) {
            board.placeStone(corner.first, corner.second, m_symbol);
            return true;
        }
    }
    return false;
}

void CComputerPlayer::makeMoveInEdge(CBoard& board) {
    static const std::pair<int, int> edges[] = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
    for (const auto& edge : edges) {
        if (!board.checkPosition(edge.first, edge.second)) {
            board.placeStone(edge.first, edge.second, m_symbol);
            return;
        }
    }
}
