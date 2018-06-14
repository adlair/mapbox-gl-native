#pragma once

#include <mbgl/tile/geometry_tile.hpp>
#include <mbgl/tile/tile_loader.hpp>

namespace mbgl {

class Tileset;
class TileParameters;

class VectorTile : public GeometryTile {
public:
    VectorTile(const OverscaledTileID&,
               std::string sourceID,
               const TileParameters&,
               const Tileset&);

    void setNecessity(TileNecessity) final;
    void setMetadata(optional<Timestamp> modified, optional<Timestamp> expires);
    uint64_t setData(std::shared_ptr<const std::string> data);

private:
    TileLoader<VectorTile> loader;
};

} // namespace mbgl
